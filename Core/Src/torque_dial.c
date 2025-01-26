#include "torque_dial.h"
#include <stdlib.h>

uint16_t dial_pins[5] = { SWITCH_1_PIN, SWITCH_2_PIN, SWITCH_3_PIN,
			  SWITCH_4_PIN, SWITCH_5_PIN };

uint8_t switch_dial_setting(uint16_t pin)
{
	uint8_t setting = -1;
	switch (pin) {
	case SWITCH_1_PIN:
		setting = SWITCH_1;
		break;
	case SWITCH_2_PIN:
		setting = SWITCH_2;
		break;
	case SWITCH_3_PIN:
		setting = SWITCH_3;
		break;
	case SWITCH_4_PIN:
		setting = SWITCH_4;
		break;
	case SWITCH_5_PIN:
		setting = SWITCH_5;
		break;
	default:
		break;
	}
	return setting;
}

// Init the dial's setting on startup
void init_dial(dial_t *dial, can_t *can, can_msg_t can_msg_dial)
{
	uint16_t pin = NULL;
	for (int i = 0; i < 5; i++) {
		if (HAL_GPIO_ReadPin(GPIOB, dial_pins[i]) == GPIO_PIN_SET) {
			pin = dial_pins[i];
			break;
		}
	}
	dial->dial_current_pin = pin;
	dial->dial_current_setting = switch_dial_setting(pin);
	memcpy(&can_msg_dial.data, &dial->dial_current_setting, 1);
	can_send_msg(can, &can_msg_dial);
	printf("Initial dial setting is %d\n", dial->dial_current_setting);
}