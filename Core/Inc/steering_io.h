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
	MAX_BUTTON_SIZE,
} steeringio_button_t;

/**
 * @brief Called when a button interrupt is triggered. Sends a CAN message with the button's id.
 */
void button_pressed(GPIO_TypeDef *port, uint16_t GPIO_Pin, uint8_t button_id, can_t *can);

/* CAN IDs */
#define BUTTON_CANID_IO 0x680
#define DIAL_CANID_IO 	0x681

/* Debounce Config */
#define DEBOUNCE_BUTTON_TIME 8 // unit is ms
#define DEBOUNCE_BUTTON_ON 1 // 0 for off, 1 for on
#define DEBOUNCE_DIAL_TIME 8 // unit is ms
#define DEBOUNCE_DIAL_ON 1 // 0 for off, 1 for on

/* Button Pins */
#define BUTTON_1_PIN GPIO_PIN_2 // PB2
#define BUTTON_2_PIN GPIO_PIN_10 // PB10
#define BUTTON_3_PIN GPIO_PIN_11 // PB11
#define BUTTON_4_PIN GPIO_PIN_7 // PA7
#define BUTTON_5_PIN GPIO_PIN_0 // PB0
#define BUTTON_6_PIN GPIO_PIN_1 // PB1