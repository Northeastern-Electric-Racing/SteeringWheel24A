
#include "can_handler.h"
#include "cmsis_os2.h"

osMessageQueueId_t can_outbound_queue;

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
