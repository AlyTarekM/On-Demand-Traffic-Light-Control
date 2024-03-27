/*
 * main.c
 *
 *  Created on: 31 Dec 2022
 *      Author: Aly Tarek
 */
#include"App/app.h"

int main(void){
	application_init();

	while(1){
		/*if(application_starter()==OK){
			continue;
		}*/
		/*GPIO_writePin(PED_LED_PORT, PED_GLED_PIN, LOGIC_HIGH);
		GPIO_Toggle(PED_LED_PORT, PED_RLED_PIN);
*/
		application_starter();
	}



	return 0;
}
