/*
 * LED.c
 *
 *  Created on: 16 Dec 2022
 *      Author: Aly Tarek
 */

#include"LED.h"
#include<util/delay.h>

void LED_init(void) {
	/*
	 * Setting up PINs direction for the Car and Pedestrian's Three LEDs
	 * as OUTPUT pins
	 */
	GPIO_setupPinDirection(CAR_LED_PORT, CAR_GLED_PIN, PIN_OUTPUT);
	GPIO_setupPinDirection(CAR_LED_PORT, CAR_YLED_PIN, PIN_OUTPUT);
	GPIO_setupPinDirection(CAR_LED_PORT, CAR_RLED_PIN, PIN_OUTPUT);

	GPIO_setupPinDirection(PED_LED_PORT, PED_GLED_PIN, PIN_OUTPUT);
	GPIO_setupPinDirection(PED_LED_PORT, PED_YLED_PIN, PIN_OUTPUT);
	GPIO_setupPinDirection(PED_LED_PORT, PED_RLED_PIN, PIN_OUTPUT);
}

void LED_OFF(uint8_t PortID, uint8_t PinID) {
	/*
	 * Writing LOGIC LOW(0) on the LED specified by the called
	 * function
	 */
	GPIO_writePin(PortID, PinID, LOGIC_LOW);
}

void LED_ON(uint8_t PortID, uint8_t PinID) {
	/*
	 * Writing LOGIC High(1) on the LED specified by the called
	 * function
	 */
	GPIO_writePin(PortID, PinID, LOGIC_HIGH);
}

void LED_Toggle(uint8_t PortID, uint8_t PinID){
	GPIO_Toggle(PortID, PinID);
	_delay_ms(500);
}
