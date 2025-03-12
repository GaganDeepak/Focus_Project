#ifndef __PUSH_BUTTON_H
#define __PUSH_BUTTON_H

#include "DEV_Config.h"

 

extern int PushButton_PIN;

void SET_PushButton_PIN(uint8_t PIN);

int   Read_PushButton_Value(void);



#endif
