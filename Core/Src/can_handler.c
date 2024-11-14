
#include "can_handler.h"
#include "cmsis_os2.h"
#include "button.h"
#include <string.h>

osMessageQueueId_t can_outbound_queue;

osStatus_t queue_button_can_msg(uint8_t button_id)
{
	can_msg_t can_msg = { .data = { 0 },
			      .len = sizeof(button_id),
			      .id = 0x01 }; // TODO: How are we defining ids?
	memcpy(&can_msg.data, &button_id, sizeof(button_id));

	return queue_can_msg(can_msg);
}

osStatus_t queue_can_msg(can_msg_t msg)
{
	if (!can_outbound_queue)
		return -1;

	osStatus_t res = osMessageQueuePut(can_outbound_queue, &msg, 0U, 0U);

	if (res) {
		printf("CAN Queue full\r\n");
	}

	osThreadFlagsSet(can_dispatch_thread, CAN_DISPATCH_FLAG);

	return res;
}
