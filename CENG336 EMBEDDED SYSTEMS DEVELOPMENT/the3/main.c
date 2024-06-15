/*
 * File:   main.c
 * Author: basar, aytac, kerem
 *
 * Created on May 23, 2024, 8:14 PM
 */
#include <xc.h>
#include "pragmas.h"
#include "prototypes.h"
#include "types.h"

/* Transmission enable & disable */
inline void disable_rxtx(void)
{
    PIE1bits.RC1IE = 0;
    PIE1bits.TX1IE = 0;
}
inline void enable_rxtx(void)
{
    PIE1bits.RC1IE = 1;
    PIE1bits.TX1IE = 1;
}

/* Initialize the buffer head & tail */
void buf_init(RingBuffer *buf)
{
    buf->head = 0;
    buf->tail = 0;
}

/* Checks if the buffer is empty */
bool buf_isempty(RingBuffer *buf){return (buf->head == buf->tail);}

void buf_push(RingBuffer *buf, uint8_t data)
{
    buf->buffer[buf->head] = data;
    (buf->head)++;
    if (buf->head == BUFSIZE)
    {
        buf->head = 0;
    }
}

uint8_t buf_pop(RingBuffer *buf)
{
    uint8_t data = 0;
    if (buf_isempty(buf))
    {
        return 0x31;
    }
    else
    {
        data = buf->buffer[buf->tail];
        (buf->tail)++;
        if (buf->tail == BUFSIZE)
        {
            buf->tail = 0;
        }
        return data;
    }
}

/* Global variables */
operation_t current_operation = IDLE;
pkt_state_t pkt_state = WAIT_HEADER;

volatile RingBuffer input_buf;
volatile RingBuffer output_buf;
volatile RingBuffer pkt_buf;

uint32_t current_distance = 0;
uint32_t current_altitude = 0;
int current_period = 0;
int period_counter = 0;
int active_state_counter = 0; // this counter is for the remaining time of ACTIVE STATE

// Flags (they are used for error checking and state control)
bool processing_cmd = false; // when processing_cmd is true, we are processing a command
bool manuel_control = false;

// Press counters
volatile int port_flag[4] = {0, 0, 0, 0};
volatile int port_previous[4] = {1, 1, 1, 1};
volatile bool press_enable[4] = {0, 0, 0, 0};
volatile int bounce_counter[4] = {0, 0, 0, 0};
volatile bool press_flag = false;
volatile int packet_valid = 0;
int led_flag=0;

/* Interrupt service routine handling */
void receive_isr(uint8_t data)
{
    buf_push(&input_buf, data);
}

void transmit_isr()
{
    disable_rxtx();
    if (buf_isempty(&output_buf))
    {
        // TXSTA1bits.TXEN = 0; // disable transmission (bu bozuyor kodu kapalı kalsın)
        // return;
    }
    else
    {
        TXREG1 = buf_pop(&output_buf);
        enable_rxtx();
    }
}

void __interrupt(high_priority) highPriorityISR(void)
{
    // PIR1bits.RC1IF is set when RCREG1 is not empty
    if (PIR1bits.RC1IF == 1)
    {
        PIR1bits.RC1IF = 0;  // Acknowledge interrupt
        receive_isr(RCREG1); // send receive byte to receive handler
    }

    // PIR1bits.TX1IF is set when the TXREGx register is empty
    if (PIR1bits.TX1IF == 1)
    {
        transmit_isr();
    }

    // Timer interrupt routine
    if (INTCONbits.TMR0IF)
    {
        INTCONbits.TMR0IF = 0;
        TMR0H = T_PRELOAD_HIGH;
        TMR0L = T_PRELOAD_LOW;

        if (current_operation == ACTIVE)
        {
            if (current_period != 0)
                period_counter++;

            if (++active_state_counter == 900)
            {
                current_operation = IDLE;
            }

            if (press_flag)
            {
                press_handler();
            }
            else
            {
                periodic_print();
            }
        }
    }
    
    if (INTCONbits.RBIF)
    {
        int x = PORTB;
        if (manuel_control&&led_flag)
        {
            if (PORTBbits.RB4 ^ port_previous[0])
            {
                // RD0 = 1;
                if (port_previous[0] == 1)
                {
                    port_flag[0] = 0;
                    port_previous[0] = 0;
                    bounce_counter[0] = 0;
                }
                else
                {
                    port_flag[0] = 1;
                    port_previous[0] = 1;
                }
            }
            if (PORTBbits.RB5 ^ port_previous[1])
            {
                // RC0 = 1;
                if (port_previous[1] == 1)
                {
                    port_flag[1] = 0;
                    port_previous[1] = 0;
                    bounce_counter[1] = 0;
                }
                else
                {
                    port_flag[1] = 1;
                    port_previous[1] = 1;
                }
            }
            if (PORTBbits.RB6 ^ port_previous[2])
            {
                // RB0 = 1;
                if (port_previous[2] == 1)
                {
                    port_flag[2] = 0;
                    port_previous[2] = 0;
                    bounce_counter[2] = 0;
                }
                else
                {
                    port_flag[2] = 1;
                    port_previous[2] = 1;
                }
            }
            if (PORTBbits.RB7 ^ port_previous[3])
            {
                // RA0 = 1;
                if (port_previous[3] == 1)
                {
                    port_flag[3] = 0;
                    port_previous[3] = 0;
                    bounce_counter[3] = 0;
                }
                else
                {
                    port_flag[3] = 1;
                    port_previous[3] = 1;
                }
            }
        }

        INTCONbits.RBIF = 0;
    }

    if (PIR1bits.ADIF)
    {
        // Clear ADC interrupt flag
        PIR1bits.ADIF = 0;
        GODONE = 1;
        if (current_operation == ACTIVE)
        {
            // Read the ADC result
            unsigned int adcValue = (ADRESH << 8) + ADRESL;

            // Map ADC value to altitude
            if (adcValue >= 768)
            {
                current_altitude = 12000;
            }
            else if (adcValue >= 512)
            {
                current_altitude = 11000;
            }
            else if (adcValue >= 256)
            {
                current_altitude = 10000;
            }
            else
            {
                current_altitude = 9000;
            }
        }
    }
}

/* Message receiving task */

/*
    - This function is polled in the main while loop.
    - When the input buffer is empty it will not be triggered.
    - When input buf get the PKT_HEADER it starts filling the
    pkt_buf.
    - Terminates when it hit the PKT_END char.
*/
void packet_task()
{
    disable_rxtx();
    if (buf_isempty(&input_buf))
    {
        enable_rxtx();
        return;
    }

    uint8_t data;
    switch (pkt_state)
    {
    case WAIT_HEADER:
        data = buf_pop(&input_buf);
        if (data == PKT_HEADER)
        {
            buf_push(&pkt_buf, data);
            pkt_state = SEND_DATA;
        }
        break;
    case SEND_DATA:
        data = buf_pop(&input_buf);
        if (data == PKT_END)
        {
            buf_push(&pkt_buf, data);
            pkt_state = WAIT_END;
            packet_valid = 1;
        }
        else if (data == PKT_HEADER)
        { // error
            pkt_state = WAIT_HEADER;
            packet_valid = 0;
        }
        else
        {
            buf_push(&pkt_buf, data);
        }
        break;
    case WAIT_END:
        if (packet_valid == 1)
        {
            break;
        }
        pkt_state = WAIT_HEADER;
        break;
    }

    enable_rxtx();
}

/* Message transmitting tasks */

// Can be used to pop any string to push output buffer.
// '\n' or '\0' should be used as last char.
void output_task(uint8_t *str)
{
    uint8_t ind = 0;
    if (current_operation == ACTIVE)
    {
        while (str[ind] != 0)
        {
            disable_rxtx();
            buf_push(&output_buf, str[ind++]);
            enable_rxtx();
        }
    }
}

/* Command processing task */

// This function is used to determine the command type
cmd_t get_command_type(uint8_t cmd)
{
    switch (cmd)
    {
    case 0x47: // G
        return GO_CMD;
    case 0x45: // E
        return END_CMD;
    case 0x53: // S
        return SPEED_CMD;
    case 0x41: // A
        return ALTITUDE_CMD;
    case 0x4D: // M
        return MANUEL_CMD;
    case 0x4C: // L
        return LED_CMD;
    default:
        return INVALID_CMD;
    }
}
void interrupt_handler()
{
    if (port_flag[0])
    { // PORT RB4
        if (bounce_counter[0]++ >= BOUNCING_LIMIT)
        {
            bounce_counter[0] = 0;
            port_flag[0] = 0;
            press_enable[0] = true;
            press_flag = true;
        }
    }
    if (port_flag[1])
    { // PORT RB5
        if (bounce_counter[1]++ >= BOUNCING_LIMIT)
        {
            bounce_counter[1] = 0;
            port_flag[1] = 0;
            press_enable[1] = true;
            press_flag = true;
        }
    }
    if (port_flag[2])
    { // PORT RB6
        if (bounce_counter[2]++ >= BOUNCING_LIMIT)
        {
            bounce_counter[2] = 0;
            port_flag[2] = 0;
            press_enable[2] = true;
            press_flag = true;
        }
    }
    if (port_flag[3])
    { // PORT RB7
        if (bounce_counter[3]++ >= BOUNCING_LIMIT)
        {
            bounce_counter[3] = 0;
            port_flag[3] = 0;
            press_enable[3] = true;
            press_flag = true;
        }
    }
}

/*
    This function checks the PORTB flags for PRS cmds
*/
void press_handler()
{
    if (press_enable[0])
    {
        send_prs(0x04);
        press_enable[0] = false;
    }
    if (press_enable[1])
    {
        send_prs(0x05);
        press_enable[1] = false;
    }
    if (press_enable[2])
    {
        send_prs(0x06);
        press_enable[2] = false;
    }
    if (press_enable[3])
    {
        send_prs(0x07);
        press_enable[3] = false;
    }
    press_flag = false;
}

// This function indirects the command to the correct function
void command_handler_indirection(cmd_t cmd, uint8_t *data)
{
    disable_rxtx();
    switch (cmd)
    {
    case GO_CMD:
        cmd_go(data);
        break;
    case END_CMD:
        cmd_end(data);
        break;
    case SPEED_CMD:
        cmd_speed(data);
        break;
    case ALTITUDE_CMD:
        cmd_altitude(data);
        break;
    case MANUEL_CMD:
        cmd_manuel(data);
        break;
    case LED_CMD:
        cmd_led(data);
        break;
    default:
        // error
        break;
    }
    enable_rxtx();
}

// This function loads the commands to some buffer and redirects it
void command_process_task()
{
    if (packet_valid)
    {

        uint8_t data;
        uint8_t cmd[9];
        uint8_t curr_idx = 0;

        cmd_t current_cmd;

        disable_rxtx();

        while (!buf_isempty(&pkt_buf))
        {
            data = buf_pop(&pkt_buf);
            if (data == PKT_HEADER)
            {
                // beginning of cmd
                if (!processing_cmd)
                {
                    cmd[curr_idx++] = data;
                    processing_cmd = true;
                    continue;
                }
            }
            else if (data == PKT_END)
            {
                // end of cmd
                if (processing_cmd)
                {

                    cmd[curr_idx] = data;
                    processing_cmd = false;
                }
                break;
            }
            else
            {
                if (curr_idx == 1)
                {
                    if (current_cmd != INVALID_CMD)
                    {
                        // Using the first byte of the cmd to determine the command type
                        // This approach can be problematic, we might need to change it
                        current_cmd = get_command_type(data);
                    }
                }
                if (current_cmd != INVALID_CMD)
                    cmd[curr_idx++] = data;
            }
        }
        packet_valid = 0;
        enable_rxtx();

        // at this point we have the command in the cmd array
        // we can process the command
        command_handler_indirection(current_cmd, cmd);
    }
}

/* Command Functions */
void cmd_go(uint8_t *data)
{
    // Expected format: $GOOXXXX#

    // Validate command format with delimiters
    if (data[1] == 'G' && data[2] == 'O' &&
        data[3] == 'O' && data[8] == '#' && data[0] == '$')
    {
        // Extract the 4-byte hexadecimal distance value
        uint32_t start_distance;

        sscanf((char *)&data[4], "%04x", &start_distance);

        // if (current_operation == IDLE)
        // {
            current_operation = ACTIVE;
            current_distance = start_distance;
            TMR0H = T_PRELOAD_HIGH;
            TMR0L = T_PRELOAD_LOW;
            T0CONbits.TMR0ON = 1;
        // }
    }
}

void cmd_end(uint8_t *data)
{
    // Expected format: $END#

    // Validate command format with delimiters
    if (data[1] == 'E' && data[2] == 'N' &&
        data[3] == 'D' && data[4] == '#' && data[0] == '$')
    {
        // Handle the error if the system is not in ACTIVE state
        if (current_operation == ACTIVE)
        {
            current_operation = END;
            current_distance = 0;
            INTCONbits.GIE = 0;
        }
    }
}


void cmd_speed(uint8_t *data)
{
    if (data[1] == 'S' && data[2] == 'P' &&
        data[3] == 'D' && data[8] == '#' && data[0] == '$')
    {
        // Extract the 4-byte hexadecimal speed value
        uint32_t speed;

        sscanf((char *)&data[4], "%04x", &speed);

        // Handle the error if the system is not in ACTIVE state
        if (current_operation == ACTIVE)
        {
            current_distance -= speed;
        }
    }
}

void cmd_altitude(uint8_t *data)
{
    if (data[1] == 'A' && data[2] == 'L' &&
        data[3] == 'T' && data[8] == '#' && data[0] == '$')
    {
        // Extract the 4-byte hexadecimal altitude value
        int altitude;

        sscanf((char *)&data[4], "%04x", &altitude);

        // Handle the error if the system is not in ACTIVE state
        if (current_operation == ACTIVE)
        {
            current_period = get_altitude_period(altitude);
            period_counter = 0;
        }
    }
}

void cmd_manuel(uint8_t *data)
{
    if (data[1] == 'M' && data[2] == 'A' &&
        data[3] == 'N' && data[6] == '#' && data[0] == '$')
    {
        // Handle the error if the system is not in ACTIVE state
        if (current_operation == ACTIVE && current_operation != END)
        {
            if (data[5] == '1')
            {
                manuel_control = true;
            }
            else if (data[5] == '0')
            {
                manuel_control = false;
            }
        }
    }
}

void cmd_led(uint8_t *data)
{
    if (data[1] == 'L' && data[2] == 'E' &&
        data[3] == 'D' && data[6] == '#' && data[0] == '$')
    {
        if (manuel_control && current_operation == ACTIVE && current_operation != END)
        {
            led_flag = 1;
            led_handler(data[5]);
        }
    }
}

/* Altitude handler */

uint8_t get_altitude_period(int altitude)
{
    switch (altitude)
    {
    case 200:
        return 1;
    case 400:
        return 2;
    case 600:
        return 3;
    default:
        return -1;
    }
}

/* Send Response */
void send_altitude(uint16_t altitude)
{
    // Send the altitude response
    char input[10];
    sprintf(input, "$ALT%04x#\0", (int)altitude);

    output_task(input);
    TXSTA1bits.TXEN = 1; // enable transmission.
}

void send_distance()
{
    // Send the distance response
    char input[10];
    sprintf(input, "$DST%04x#\0", (int)current_distance);

    output_task(input);
    TXSTA1bits.TXEN = 1; // enable transmission.
}

void periodic_print()
{
    switch (current_period)
    {
    case -1:
        send_distance();
        GODONE = 0;
        current_period = 0;
        break;
    case 1:
        if (period_counter == 2)
        {
            send_altitude(current_altitude);
            period_counter = 0;
        }
        else
        {
            send_distance();
        }
        break;
    case 2:
        if (period_counter == 4)
        {
            send_altitude(current_altitude);
            period_counter = 0;
        }
        else
        {
            send_distance();
        }
        break;
    case 3:
        if (period_counter == 6)
        {
            send_altitude(current_altitude);
            period_counter = 0;
        }
        else
        {
            send_distance();
        }
        break;
    default:
        send_distance();
        break;
    }
}

void send_prs(uint8_t prs)
{
    // Send the LED response
    char input[8];
    sprintf(input, "$PRS%02x#\0", prs);

    output_task(input);
    TXSTA1bits.TXEN = 1; // enable transmission.
}

void led_handler(uint8_t led_bit)
{
    switch (led_bit)
    {
    case '0':
        LATD = LATC = LATB = LATA = 0;
        led_flag = 0;
        break;
    case '1':
        LATDbits.LATD0 = 1;
        break;
    case '2':
        LATCbits.LATC0 = 1;
        break;
    case '3':
        LATBbits.LATB0 = 1;
        break;
    case '4':
        LATAbits.LATA0 = 1;
        break;
    default:
        break;
    }
}

/* Init processes */
void start_system()
{
    INTCONbits.GIE = 1;
}

void init_ports()
{
   
    // Set the port values
    PORTA = 0x00;
    //PORTB = 0x00;
    PORTC = 0x00;
    PORTD = 0x00;
    PORTE = 0x00;
    PORTH = 0x00;

    LATA = 0x00;
    //LATB = 0x00;
    LATC = 0x00;
    LATD = 0x00;
    LATE = 0x00;
    LATH = 0x00;

    TRISD = 0x00;
    TRISC = 0x00;
    TRISA = 0x00;

    // Set the portb for input
    TRISB = 0xF0; // 1111 0000
}
void init_interrupt()
{
    INTCON = 0;
    INTCONbits.TMR0IE = 1;
    INTCONbits.RBIE = 1;

    INTCON2 = 0;
    INTCON2bits.RBPU = 0;

    T0CON = 0;

    // scale timer
    T0CONbits.T0PS2 = 1;
    T0CONbits.T0PS1 = 0;
    T0CONbits.T0PS0 = 1;
    TMR0H = T_PRELOAD_HIGH;
    TMR0L = T_PRELOAD_LOW;

    PIE1bits.ADIE = 1;
    PIE1bits.RC1IE = 1;
    PIE1bits.TX1IE = 1;
    INTCONbits.PEIE = 1;
}

void init_serial()
{
    TRISCbits.RC7 = 1;
    TRISCbits.RC6 = 0;
    TXSTA = 0x04;  // (= 00000100) 8-bit transmit, transmitter NOT enabled,TXSTA1.TXEN not enabled!
    RCSTA1 = 0x90; // (= 10010000) 8-bit receiver, receiver enabled,
    BAUDCONbits.BRG16 = 0;
    SPBRG1 = 21;
}

void init_adc()
{
    // Set ADC Inputs
    TRISH = 0x10; // AN12 input RH4

    // Configure ADC
    ADCON0 = 0x31;

    ADCON1 = 0x00; // All analog pins

    ADCON2 = 0xAA; // Right justified result, 12 TAD acquisition time, FOSC/32 conversion clock
    // ADCON2bits.ADCS = 0b010; // ADC conversion clock select: FOSC/32
    // ADCON2bits.ACQT = 0b101; // Acquisition time select: 12 TAD (experimentally determined)
    // ADCON2bits.ADFM = 1;     // Right justified result

    // will be configured
    ADRESH = 0x00;
    ADRESL = 0x00;

    GODONE = 1;          // Start conversion
    ADCON0bits.ADON = 1; // Turn on AD Converter
    // Enable ADC interrupt
    PIE1bits.ADIE = 1; // Enable ADC interrupt
    PIR1bits.ADIF = 0; // Clear ADC interrupt flag
}

void main(void)
{
    buf_init(&input_buf);
    buf_init(&output_buf);
    buf_init(&pkt_buf);

    init_ports();
    init_interrupt();
    init_serial();
    init_adc();
    start_system();

    while (31 && current_operation != END)
    {
        packet_task();
        command_process_task();
        interrupt_handler();
    }
    return;
}
