/*
 * app.h
 *
 *  Created on: 30 Dec 2022
 *      Author: Aly Tarek
 */

#ifndef APP_APP_H_
#define APP_APP_H_

#include"../HAL/ButtonD/button.h"
#include"../HAL/LEDDr/LED.h"

typedef enum{
	GREEN,YELLOW,RED
}Traffic_Color;

typedef enum{
	OK,ERROR
}State_Check;


void application_init(void);

State_Check application_starter(void);





#endif /* APP_APP_H_ */
