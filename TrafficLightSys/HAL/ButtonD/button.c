/*
 * button.c
 *
 *  Created on: 15 Dec 2022
 *      Author: Aly Tarek
 */


#include"button.h"

void Button_Init(void){
	//Setting Up Button's Direction to Input
	GPIO_setupPinDirection(BUTTON_PORT_ID, BUTTON_PIN_ID, PIN_INPUT);
}
Button_State IsPressed(void){
	//Read Wether the Button is Pressed or NOT
	uint8_t Button_State;
	Button_State=GPIO_readPin(BUTTON_PORT_ID, BUTTON_PIN_ID);
	if(Button_State==LOGIC_HIGH){
		return PRESSED;
	}
	else{
		return NOT_PRESSED;
	}
}
