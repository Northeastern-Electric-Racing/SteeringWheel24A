#include "main.h"
#include "can.h"
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef enum {
	BUTTON_LEFT,
	BUTTON_RIGHT,
	BUTTON_ESC,
	BUTTON_UP,
	BUTTON_DOWN,
	BUTTON_ENTER,
	SPARE_BUTTON,
	MAX_BUTTON_SIZE,
} steeringio_button_t;

typedef enum {
	DIAL_SWITCH_1,
	DIAL_SWITCH_2,
	DIAL_SWITCH_3,
	DIAL_SWITCH_4,
	DIAL_SWITCH_5,
	MAX_DIAL_SIZE,
} steeringio_dial_t;

/**
 * @brief Called when a button interrupt is triggered. Sends a CAN message with the button's id.
 */
void button_pressed(GPIO_TypeDef *port, uint16_t GPIO_Pin, uint8_t button_id,
		    can_t *can);

/**
 * @brief Called when a dial switch interrupt is triggered. Sends a CAN message with the dial switch's id.
 */
void dial_switched(GPIO_TypeDef *port, uint16_t GPIO_Pin, uint8_t switch_id,
		   can_t *can);

/* CAN IDs */
#define BUTTON_CANID_IO 0x680
#define DIAL_CANID_IO	0x681

/* Debounce Config */
#define DEBOUNCE_BUTTON_TIME 8 // unit is ms
#define DEBOUNCE_BUTTON_ON   1 // 0 for off, 1 for on
#define DEBOUNCE_DIAL_TIME   8 // unit is ms
#define DEBOUNCE_DIAL_ON     1 // 0 for off, 1 for on

/* Button Pins */
#define BUTTON_1_PIN GPIO_PIN_2 // PB2
#define BUTTON_2_PIN GPIO_PIN_10 // PB10
#define BUTTON_3_PIN GPIO_PIN_11 // PB11
#define BUTTON_4_PIN GPIO_PIN_4 // PA4
#define BUTTON_5_PIN GPIO_PIN_0 // PB0
#define BUTTON_6_PIN GPIO_PIN_1 // PB1
#define SPARE_BUTTON_PIN GPIO_PIN_3 // PA3

/* Dial Switch Pins */
#define SWITCH_1_PIN GPIO_PIN_5 // PB5
#define SWITCH_2_PIN GPIO_PIN_6 // PB6
#define SWITCH_3_PIN GPIO_PIN_7 // PB7
#define SWITCH_4_PIN GPIO_PIN_8 // PB8
#define SWITCH_5_PIN GPIO_PIN_9 // PB9