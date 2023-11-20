/*Se incluye el header creado para API delay*/
#include "../Inc/API_delay.h"

/*Se deine un rango valido para control de parametros en el tiempo de delay*/
#define MAXDURATION 1000//maxima duracion de 100 s
#define MINDURATION 0

/*En la funcion DelayInt se debe cargar el valor de duración del retardo
 *en la estructura en el campo correspondiente y se inicializa el flag running en falso,
 primero se verifica que el valor de duration se encuentre en el rango definido*/
void delayInit(delay_t * delay, tick_t duration)
{
	assert(MINDURATION<duration && MAXDURATION>duration);
	delay->duration=duration;
	delay->running=false;
	delay->startTime=0;
}

/*La funcion delayRead realiza lo siguiente:
   verifica el estado de running, si es false, toma marca de tiempo y cambia running a ‘true’
   Si es true, realiza la cuenta para saber si el tiempo del retardo se cumplió o no
   Cuando el tiempo se cumple se cambia  running a false.
 */
bool_t delayRead(delay_t * delay)
{
	if(delay->running==false)
	{
		delay->running=true;
		delay->startTime=HAL_GetTick();//obtiene el tiempo actual
	}
	else
	{
		if(HAL_GetTick()-delay->startTime>=delay->duration)//compara la delta del tiempo actual contra la duracion en ms
			{
			delay->running=false;//si se ha cumplido la condicion el retardo cambia false
			return true;//retorna un valor verdadero y regresa

			}
	}
	return false;//si no se ha cumplido la condicion de tiempo, retorna falso
}

void delayWrite(delay_t*delay, tick_t duration)
{
	delay->duration=duration;//permite cambiar el valor de duracion
}/*
 * API_delay.c
 *
 *  Created on: Nov 5, 2023
 *      Author: Luis Herrera
 */


