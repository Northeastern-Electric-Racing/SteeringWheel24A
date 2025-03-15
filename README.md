# SteeringWheel24A
Code for NER's 24A Steering Wheel

When regenerating CubeMX, you need to set clear bit from lines above the request for initialization around line 333 in stm32f1xx_hal_can.c

```
 /* Exit from sleep mode */
  CLEAR_BIT(hcan->Instance->MCR, CAN_MCR_SLEEP);
```