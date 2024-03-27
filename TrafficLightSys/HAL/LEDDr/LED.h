/*
 * LED.h
 *
 *  Created on: 16 Dec 2022
 *      Author: Aly Tarek
 */

#ifndef HAL_LEDDR_LED_H_
#define HAL_LEDDR_LED_H_

#include"../../MCAL/GPIO/gpio.h"
#include"../../MCAL/Timer/timer.h"
#include"std_types.h"

#define CAR_LED_PORT PORTA_ID
#define CAR_GLED_PIN PIN0_ID
#define CAR_YLED_PIN PIN1_ID
#define CAR_RLED_PIN PIN2_ID

#define PED_LED_PORT PORTB_ID
#define PED_GLED_PIN PIN0_ID
#define PED_YLED_PIN PIN1_ID
#define PED_RLED_PIN PIN2_ID

void LED_init(void);

void LED_OFF(uint8_t PortID,uint8_t PinID);


void LED_ON(uint8_t PortID,uint8_t PinID);

void LED_Toggle(uint8_t PortID,uint8_t PinID);






#endif /* HAL_LEDDR_LED_H_ */
