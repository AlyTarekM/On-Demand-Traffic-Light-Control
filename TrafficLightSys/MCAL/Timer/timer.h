/*
 * timer.h
 *
 *  Created on: 30 Dec 2022
 *      Author: Aly Tarek
 */

#ifndef MCAL_TIMER_TIMER_H_
#define MCAL_TIMER_TIMER_H_

#include"common_macros.h"
#include"std_types.h"

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

typedef enum{
	NORMAL,CTC
}Timer_Mode;

typedef enum{
	NO_CLOCK,CLCK_PRESCALER_1,CLCK_PRESCALER_8,CLCK_PRESCALER_64,CLCK_PRESCALER_256,CLCK_PRESCALER_1024,CLCK_FALLING,CLCK_RISING
}Timer_Prescaler;


typedef struct{
	uint16 starting_value;
	uint16 compare_value;
	Timer_Prescaler prescaler;
	Timer_Mode mode;

}Timer_Config;


/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

void Timer_Init(Timer_Config *Config_PTR);

void Timer_SetCallback(void(*call_ptr)(void));

void Timer_DeInit(void);

void INT0_Init(void);


#endif /* MCAL_TIMER_TIMER_H_ */
