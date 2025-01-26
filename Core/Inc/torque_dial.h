#include <stdint.h>
#include <stdbool.h>
#include "main.h"
#include "can.h"

#define SWITCH_1_PIN GPIO_PIN_5 // PB5
#define SWITCH_2_PIN GPIO_PIN_6 // PB6
#define SWITCH_3_PIN GPIO_PIN_7 // PB7
#define SWITCH_4_PIN GPIO_PIN_8 // PB8
#define SWITCH_5_PIN GPIO_PIN_9 // PB9

typedef enum {
	SWITCH_1,
	SWITCH_2,
	SWITCH_3,
	SWITCH_4,
	SWITCH_5,
	MAX_DIAL_SIZE,
} dial_switches_t;

typedef struct dial {
    uint8_t dial_current_setting;
	uint32_t prev_tick;
	bool actively_debouncing;
} dial_t;

/**
 * @brief Initializes torque dial
 */
void init_dial(dial_t *dial, can_t *can, can_msg_t can_msg_dial);

/**
 * @brief Switches dial setting
 */
uint8_t switch_dial_setting(uint16_t pin);