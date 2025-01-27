
#include "steering_io.h"
#include <stdlib.h>

void button_pressed(GPIO_TypeDef *port, uint16_t GPIO_Pin, uint8_t button_id, can_t *can)
{
	/* Debounce Logic */
	if(DEBOUNCE_BUTTON_ON) {
		HAL_Delay(DEBOUNCE_BUTTON_TIME);
		if (HAL_GPIO_ReadPin(port, GPIO_Pin) == GPIO_PIN_RESET)
		{
			printf("Failed to read the pin for button %d when doing debounce check.\n", button_id);
			return;
		}
	}

	/* Send CAN Message */
	can_msg_t can_msg = { .len = sizeof(uint8_t), .id = BUTTON_CANID_IO };
	memcpy(&can_msg.data, &button_id, 1);
	can_send_msg(can, &can_msg);
	printf("Button %d pressed\n", button_id);
}