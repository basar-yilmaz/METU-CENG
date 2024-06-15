#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>

#define BUFSIZE 128     // The buffer size of the any buffer in this code
#define PKT_HEADER 0x24 // Marker for start-of-packet $ (ASCII)
#define PKT_END 0x23    // Marker for end-of-packet # (ASCII)


#define T_PRELOAD_HIGH 0xc2
#define T_PRELOAD_LOW 0xf7
#define BOUNCING_LIMIT 150
// Enum Definitions

// Operation States
typedef enum
{
    IDLE,   // Wait for 's' from keyboard, then simulator will send GO cmd
    ACTIVE, // The sim expects serial cmd, 90s
    END     // Terminate further events
} operation_t;

// Command Types
typedef enum
{
    GO_CMD,       // $GOOXXXX#  -> 9 bytes, XXXX is distance
    END_CMD,      // $END#      -> 5 bytes
    SPEED_CMD,    // $SPDXXXX#  -> 9 bytes, XXXX is speed
    ALTITUDE_CMD, // $ALTXXXX#  -> 9 bytes, XXXX is altitude
    MANUEL_CMD,   // $MANXX#    -> 7 bytes XX is activating or deactivating
    LED_CMD,      // $LEDXX#    -> 7 bytes
    INVALID_CMD
} cmd_t;

// States for the received packets
typedef enum
{
    WAIT_HEADER,
    SEND_DATA,
    WAIT_END
} pkt_state_t;

// Struct Definition
typedef struct
{
    uint8_t buffer[BUFSIZE]; // Adjusted BUFSIZE
    volatile int head;
    volatile int tail;
} RingBuffer;

#endif // TYPES_H
