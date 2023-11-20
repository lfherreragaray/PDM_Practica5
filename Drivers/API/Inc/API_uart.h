/*
 * API_uart.h
 *
 *  Created on: Nov 20, 2023
 *      Author: ubuntu
 */

#ifndef API_INC_API_UART_H_
#define API_INC_API_UART_H_
#endif /* API_INC_API_UART_H_ */

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


bool_t uartInit(uint32_t baudRate);
void uartSendString(uint8_t *p_String);
void uartSendStringSize(uint8_t *p_String,uint8_t size);
void uartReceiveStringSize(uint8_t *p_String,uint8_t size);

