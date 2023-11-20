/*
 * API_debounce.h
 *
 *  Created on: Nov 19, 2023
 *      Author: ubuntu
 */

//#ifndef API_INC_API_DEBOUNCE_H_
#define API_INC_API_DEBOUNCE_H_
//#endif

#ifndef __STDINT_H
#include "stdint.h"
#endif

#ifndef __STDBOOL_H
#include "stdbool.h"
#endif

#ifndef __ASSERT_H
#include <assert.h>
#endif

#include "stm32f4xx_hal.h"

#ifndef INC_API_DELAY_H_
#include "API_delay.h"
#endif /* INC_API_DELAY_H_ */

void buttonPressed();
void buttonReleased();

void debounceFSM_Init();
void debounceFSM_Update();

bool_t readKeyAsc();
bool_t readKeyDes();

