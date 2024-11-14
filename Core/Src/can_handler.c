
#include "can_handler.h"
#include "cmsis_os2.h"

osThreadId_t can_dispatch_thread;
const osThreadAttr_t can_dispatch_attrs = {
	.name = "Can Dispatch",
	.stack_size = 128 * 8,
	.priority = (osPriority_t)osPriorityRealtime5,
};

osMessageQueueId_t can_outbound_queue;

void vCanDispatch(void *pv_params)
{
	can_msg_t msg_from_queue;
	HAL_StatusTypeDef msg_status;
	can_t *can = (can_t *)(pv_params);

	for (;;) {
		osThreadFlagsWait(CAN_DISPATCH_FLAG, osFlagsWaitAny,
				  osWaitForever);
		while (osMessageQueueGet(can_outbound_queue, &msg_from_queue,
					 NULL, 0) == osOK) {
			msg_status = can_send_msg(can, &msg_from_queue);
			if (msg_status == HAL_ERROR) {
				// temporary
				printf("CAN ERROR\r\n");
				// TODO: error handling
				// fault_data.diag = "Failed to send CAN message";
			} else if (msg_status == HAL_BUSY) {
				// temporary
				printf("CAN BUSY\r\n");
				// TODO: error handling
				//"Outbound mailbox full!";
			}
		}

		osDelay(CAN_DISPATCH_DELAY);
	}
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
