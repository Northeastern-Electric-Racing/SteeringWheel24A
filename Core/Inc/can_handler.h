#ifndef CAN_HANDLER_H
#define CAN_HANDLER_H

#include "cmsis_os.h"
#include "can.h"
#include <stdio.h>

#define CAN_DISPATCH_FLAG  1
#define CAN_DISPATCH_DELAY 5

extern osMessageQueueId_t can_outbound_queue;
extern osThreadId_t can_dispatch_thread;
extern const osThreadAttr_t can_dispatch_attrs;

/**
 * @brief queues can message in can dispatch thread
 * 
 * @param can_msg
 */
osStatus_t queue_can_msg(can_msg_t can_msg);

#endif