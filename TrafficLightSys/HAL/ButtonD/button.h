/*
 * button.h
 *
 *  Created on: 15 Dec 2022
 *      Author: Aly Tarek
 */

#ifndef HAL_BUTTOND_BUTTON_H_
#define HAL_BUTTOND_BUTTON_H_

#include"../../MCAL/GPIO/gpio.h"
#include"../../MCAL/Timer/timer.h"


#define BUTTON_PORT_ID PORTD_ID
#define BUTTON_PIN_ID PIN2_ID

typedef enum{
	NOT_PRESSED,PRESSED
}Button_State;

void Button_Init(void);

Button_State IsPressed(void);


#endif /* HAL_BUTTOND_BUTTON_H_ */
