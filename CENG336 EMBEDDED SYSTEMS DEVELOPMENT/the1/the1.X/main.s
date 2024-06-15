PROCESSOR 18F8722

#include <xc.inc>

; CONFIGURATION (DO NOT EDIT)
; CONFIG1H
CONFIG OSC = HSPLL      ; Oscillator Selection bits (HS oscillator, PLL enabled (Clock Frequency = 4 x FOSC1))
CONFIG FCMEN = OFF      ; Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
CONFIG IESO = OFF       ; Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)
; CONFIG2L
CONFIG PWRT = OFF       ; Power-up Timer Enable bit (PWRT disabled)
CONFIG BOREN = OFF      ; Brown-out Reset Enable bits (Brown-out Reset disabled in hardware and software)
; CONFIG2H
CONFIG WDT = OFF        ; Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
; CONFIG3H
CONFIG LPT1OSC = OFF    ; Low-Power Timer1 Oscillator Enable bit (Timer1 configured for higher power operation)
CONFIG MCLRE = ON       ; MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)
; CONFIG4L
CONFIG LVP = OFF        ; Single-Supply ICSP Enable bit (Single-Supply ICSP disabled)
CONFIG XINST = OFF      ; Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))
CONFIG DEBUG = OFF      ; Disable In-Circuit Debugger



GLOBAL counter
    
GLOBAL i
GLOBAL j
GLOBAL k
    
GLOBAL rd0_cont
    
GLOBAL re0_cont

GLOBAL re1_cont
    
GLOBAL re_counter
GLOBAL buttons_counter
    
GLOBAL b_state_0

GLOBAL b_state_1

GLOBAL dummy_re0
GLOBAL dummy_re1


; Define space for the variables in RAM
PSECT udata_acs
counter:
    DS 1
    
i:
    DS 1
j:
    DS 1
k:
    DS 1
    
rd0_cont:
    DS 1
    
re0_cont:
    DS 1

    
re1_cont:
    DS 1

    
re_counter:
    DS 1
buttons_counter:
    DS 1

b_state_0:
    DS 1
b_state_1:
    DS 1
    
dummy_re0:
    DS 1
dummy_re1:
    DS 1
PSECT resetVec,class=CODE,reloc=2
resetVec:
    goto       init

    
PSECT CODE
init:
    clrf counter
    
    clrf i
    clrf j
    clrf k
    
    clrf rd0_cont
    
    clrf re0_cont
    clrf re1_cont
    
    clrf re_counter
    clrf buttons_counter
    
    clrf b_state_0
    clrf b_state_1
    clrf dummy_re0
    clrf dummy_re1
    
    ; clrf TRISx
    clrf TRISB	; PORTB output
    clrf TRISC	; PORTC output
    clrf TRISD	; PORTD output
    setf TRISE	; PORTE input
    
    ; write to LATCH read from PORT
    setf LATB
    setf LATC
    setf LATD	; light all pins in PORTD
    
    call busy_wait
    
    clrf LATB
    clrf LATC
    clrf LATD
    
    movlw 190
    movwf rd0_cont
    
    movlw 170
    movwf re_counter
    
    movlw 48
    movwf buttons_counter
    
main_loop:
    call button_tracker_0
    call button_tracker_1
    call button_sync 
    ; call rd0_handler
    goto main_loop  
    
button_sync:
    ; set the timer 
    incfsz buttons_counter
    return
    incfsz re_counter
    return
    call rd0_routine
    call check_buttons
    return
    
    
rd0_handler:
    infsnz counter  ; counter++ skip if not 0
    call rd0_continous
    return
    
rd0_continous:
    infsnz rd0_cont ; rd0_cont skip if not 0
    call rd0_routine
    return    

rd0_routine:
    ; movlw 190
    ; movwf rd0_cont
    btg LATD, 0
    return

button_pressed_1:
    bsf b_state_1, 0 ; Set bit 0 to indicate button is pressed
    return
    
button_tracker_1:
    ; check if button is pressed (pin 0)
    btfsc PORTE, 1
    goto button_pressed_1
    
    ; skip if released
    btfss b_state_1, 0
    return
    
    clrf b_state_1
    incf dummy_re1
    return

clear_bar_1:
    clrf re1_cont
    clrf LATB
    clrf dummy_re1
    return
    
re1_routine:
    movlw 1
    cpfseq dummy_re1	; we get another RE1 signal
    goto clear_bar_1
    
    
    btfss re1_cont, 0
    goto re1_routine_start  ; goto if re1 = 1, re1_cont = 0
   
    goto re1_routine_cont
    
re1_routine_start:		
    btg re1_cont, 0	; RE0 1 olarak kaydettik
    movlw 1		; write to lat read from port principle
    addwf LATB		; set MSB of PORTB (LATB)
    return

        
bar_shift_left:
    movlw 1
    rlcf LATB, 1    ; shift LATB to left
    addwf LATB
    return
    
re1_routine_cont:
    btfss re1_cont, 0
    return  ; if re1_cont = 0 & re1 = 0
    
    ; if re1_cont = 1 & re1 = 0
    ; in this case there exists already 
    ; at least 1 bit in PORTB
    ; existing bits should be shifted to left
    ; and add 1 bit to lsb
    ; check if all bits are full
    movlw 0xFFFF
    cpfseq PORTB  ; TRUE if all bits are set
    goto bar_shift_left
    
    clrf LATB
    return

    
button_pressed_0:
    bsf b_state_0, 0 ; Set bit 0 to indicate button is pressed
    return
    
button_tracker_0:
    ; check if button is pressed (pin 0)
    btfsc PORTE, 0
    goto button_pressed_0
    
    ; skip if released
    btfss b_state_0, 0
    return
    
    clrf b_state_0
    incf dummy_re0
    return
    
clear_bar_0:
    clrf re0_cont
    clrf LATC
    clrf dummy_re0
    return
    
re0_routine:    
    
    movlw 1
    cpfseq dummy_re0	; we get another RE0 signal
    goto clear_bar_0
    
    
    btfss re0_cont, 0
    goto re0_routine_start  ; goto if re0 = 1, re0_cont = 0
   
    goto re0_routine_cont
    ; return
    
re0_routine_start:
    btg re0_cont, 0	; RE0 1 olarak kaydettik
    movlw 128		; write to lat, read from port principle
    addwf LATC		; set MSB of PORTC (LATC)  
    return
        
    
bar_shift_right:
    movlw 128
    rrcf LATC, 1    ; shift LATC to right
    addwf LATC
    return
    
re0_routine_cont:	
    btfss re0_cont, 0
    return  ; if re0_cont = 0 & re0 = 0
    
    ; if re0_cont = 1 & re0 = 0
    ; in this case there exists already 
    ; at least 1 bit in PORTC
    ; existing bits should be shifted to right
    ; and add 1 bit to msb
    ; check if all bits are full
    movlw 0xFFFF
    cpfseq PORTC  ; TRUE if all bits are set
    goto bar_shift_right
    
    clrf LATC
    ; clrf re0_cont
    return

    
check_buttons:		
    ; this func checks input ports
    ; reset re_counter & buttons_counter
    
    
    movlw 170
    movwf re_counter
    movlw 48
    movwf buttons_counter

    	
    call re0_routine
    call re1_routine
    
    return		  

    
busy_wait:		; waits 1.004587s
    movlw 250
    movwf k, 0
    outer_outer_loop_start:
	movlw 38
	movwf j, 0
	outer_loop_start:
	    setf i	; var1 = 255
	    loop_start:
		decf i
		bnz loop_start
	    incfsz j
	    bra outer_loop_start
	incfsz k
	bra outer_outer_loop_start
    return
    
end resetVec