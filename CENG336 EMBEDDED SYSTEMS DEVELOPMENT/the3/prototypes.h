#ifndef PROTOTYPES_H
#define PROTOTYPES_H

#include "types.h"
#include <stdint.h>
#include <stdbool.h>

// Function Prototypes
void packet_task();
void output_task();
void send_altitude(uint16_t altitude);
void send_distance();
void periodic_print();
void send_prs(uint8_t prs);
void led_handler(uint8_t led);

cmd_t get_command_type(uint8_t cmd);
uint8_t get_altitude_period(int altitude);

void command_handler_indirection(cmd_t cmd, uint8_t *data);
void command_process_task();
void cmd_go(uint8_t *data);
void cmd_end(uint8_t *data);
void cmd_speed(uint8_t *data);
void cmd_altitude(uint8_t *data);
void cmd_manuel(uint8_t *data);
void cmd_led(uint8_t *data);

bool buf_isempty(RingBuffer *buf);
void buf_init(RingBuffer *buf);
void buf_push(RingBuffer *buf, uint8_t data);
uint8_t buf_pop(RingBuffer *buf);

inline void disable_rxtx(void);
inline void enable_rxtx(void);

void interrupt_handler();
void press_handler();


#endif // PROTOTYPES_H
