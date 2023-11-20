/*
 * API_delay.h
 *
 *  Created on: Nov 5, 2023
 *      Author: Luis Herrera
 */
/*Se agregan las librerias necesarias para la ejecucion de la API delay*/

#ifndef __STM32F4XX_HAL_H_
#include "stm32f4xx_hal.h"
#endif
#include "stm32f4xx_hal.h"
#ifndef INC_API_DELAY_H_
#define INC_API_DELAY_H_
#endif /* INC_API_DELAY_H_ */
#ifndef __STDINT_H
#include "stdint.h"
#endif
#ifndef __STDBOOL_H
#include "stdbool.h"
#endif
#ifndef __ASSERT_H
#include <assert.h>
#endif
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
/*Se crean tipos de datos definidos: tick_t, bool_t y delay_t*/
typedef uint32_t tick_t;
typedef bool bool_t;
void delayStruct();
typedef struct
	{
		tick_t startTime;
		tick_t duration;
		bool_t running;
	}delay_t;

/*Se agregan los prototipos de las funciones las cuales estan implementadas en API delay.c*/
void getTick(tick_t time);

void delayInit(delay_t*delay,tick_t duration);
bool_t delayRead(delay_t*delay);
void delayWrite(delay_t*delay, tick_t duration);
