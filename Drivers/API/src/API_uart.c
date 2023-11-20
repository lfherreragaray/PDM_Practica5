/*
 * API_uart.c
 *
 *  Created on: Nov 20, 2023
 *      Author: ubuntu
 */

#include "API_uart.h"
UART_HandleTypeDef UART2_HANDLE;
const uint16_t timeOut=200;

bool_t uartInit(uint32_t baudRate)
    {
    UART2_HANDLE.Instance=USART2;
    UART2_HANDLE.Init.BaudRate=baudRate;
    UART2_HANDLE.Init.WordLength=UART_WORDLENGTH_8B;
    UART2_HANDLE.Init.StopBits=UART_STOPBITS_1;
    UART2_HANDLE.Init.Parity=UART_PARITY_NONE;
    UART2_HANDLE.Init.Mode=UART_MODE_TX_RX;
    UART2_HANDLE.Init.HwFlowCtl=UART_HWCONTROL_NONE;
    UART2_HANDLE.Init.OverSampling=UART_OVERSAMPLING_16;

    if(HAL_UART_Init(&UART2_HANDLE)!=HAL_OK)

	return false;

    else return true;
    }

void uartSendString(uint8_t *p_String)
    {
    uint8_t i=0;
    while(p_String[i]!='\0')
	i++;
    uartSendStringSize(p_String, i);
    }

void uartSendStringSize(uint8_t *p_String,uint8_t size)
    {
    HAL_UART_Transmit(&UART2_HANDLE, p_String, size, timeOut);

    }

void uartReceiveStringSize(uint8_t *p_String,uint8_t size)
    {
    HAL_UART_Receive(&UART2_HANDLE, p_String, size, timeOut);

    }
