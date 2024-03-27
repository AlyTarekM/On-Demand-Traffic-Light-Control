/*
 * app.c
 *
 *  Created on: 30 Dec 2022
 *      Author: Aly Tarek
 */

#include"app.h"
#include<avr/interrupt.h>
#include<avr/io.h>
#include<util/delay.h>

uint8_t g_mode = 0; //0 for normal 1 for pedestrian
Traffic_Color Color_Flag;
uint8_t g_pedestrianCheck = 1;
State_Check Pedestrian_State;
State_Check Normal_State;

ISR(INT0_vect) {
	g_mode = 1;//Setting Mode as Pedestrian
}

void application_init(void) {
	/*
	 * Initializing LED's and the Push Button using the init
	 * functions.
	 * Also initializing the timer using timer init
	 */

	LED_init();
	Button_Init();
	Timer_Config Config_PTR = { 0, 7812, CLCK_PRESCALER_1024, CTC };
	Timer_Init(&Config_PTR);
	INT0_Init();
	sei(); //Enable Interrupts
}

State_Check Normal_Mode(void) {
	static uint8_t Normal_Tick = 0;
	Normal_Tick++;
	if (Normal_Tick < 6) {
		Color_Flag = GREEN;
		LED_OFF(PED_LED_PORT, PED_GLED_PIN);
		LED_OFF(PED_LED_PORT, PED_RLED_PIN);
		LED_ON(CAR_LED_PORT, CAR_GLED_PIN);
		LED_OFF(CAR_LED_PORT, CAR_RLED_PIN);
		LED_OFF(CAR_LED_PORT, CAR_YLED_PIN);
		LED_OFF(PED_LED_PORT, PED_YLED_PIN);
	} else if (Normal_Tick >= 6 && Normal_Tick < 11) {
		Color_Flag = YELLOW;
		LED_ON(CAR_LED_PORT, CAR_GLED_PIN);
		LED_OFF(CAR_LED_PORT, CAR_RLED_PIN);
		LED_Toggle(CAR_LED_PORT, CAR_YLED_PIN);

	} else if (Normal_Tick >= 11 && Normal_Tick < 16) {
		Color_Flag = RED;
		LED_OFF(CAR_LED_PORT, CAR_GLED_PIN);
		LED_ON(CAR_LED_PORT, CAR_RLED_PIN);
		LED_OFF(CAR_LED_PORT, CAR_YLED_PIN);
	} else if (Normal_Tick >= 16 && Normal_Tick < 21) {
		LED_Toggle(CAR_LED_PORT, CAR_YLED_PIN);
		LED_ON(CAR_LED_PORT, CAR_RLED_PIN);
	} else {
		Normal_Tick = 0;
		Normal_State = OK;
	}
	return Normal_State;
}

State_Check Pedestrian_Mode(void) {
	static uint8_t Pedestrian_Tick = 0;
	Pedestrian_Tick++;
	uint8_t isGreen=0;
	if (Color_Flag == GREEN || Color_Flag == YELLOW) {

		if (Pedestrian_Tick == 1) {
			LED_OFF(CAR_LED_PORT, CAR_GLED_PIN);
			LED_OFF(CAR_LED_PORT, CAR_YLED_PIN);
			LED_OFF(PED_LED_PORT, PED_RLED_PIN);

			LED_ON(PED_LED_PORT, PED_YLED_PIN);
			LED_ON(CAR_LED_PORT, CAR_YLED_PIN);

		} else if (Pedestrian_Tick == 2) {
			LED_OFF(PED_LED_PORT, PED_YLED_PIN);
			LED_OFF(CAR_LED_PORT, CAR_YLED_PIN);
		} else if (Pedestrian_Tick == 3) {
			LED_ON(PED_LED_PORT, PED_YLED_PIN);
			LED_ON(CAR_LED_PORT, CAR_YLED_PIN);
		} else if (Pedestrian_Tick == 4) {
			LED_OFF(PED_LED_PORT, PED_YLED_PIN);
			LED_OFF(CAR_LED_PORT, CAR_YLED_PIN);
		} else if (Pedestrian_Tick == 5) {
			LED_ON(PED_LED_PORT, PED_YLED_PIN);
			LED_ON(CAR_LED_PORT, CAR_YLED_PIN);
		} else if (Pedestrian_Tick == 6) {

			LED_OFF(PED_LED_PORT, PED_YLED_PIN);
			LED_OFF(CAR_LED_PORT, CAR_YLED_PIN);
			LED_ON(CAR_LED_PORT, CAR_RLED_PIN);
			LED_OFF(PED_LED_PORT, PED_RLED_PIN);
			LED_ON(PED_LED_PORT, PED_GLED_PIN);
		} else if (Pedestrian_Tick == 11) {
			LED_OFF(CAR_LED_PORT, CAR_RLED_PIN);
			LED_ON(PED_LED_PORT, PED_YLED_PIN);
			LED_ON(CAR_LED_PORT, PED_YLED_PIN);

		} else if (Pedestrian_Tick == 12) {
			LED_OFF(PED_LED_PORT, PED_YLED_PIN);
			LED_OFF(CAR_LED_PORT, CAR_YLED_PIN);
		} else if (Pedestrian_Tick == 13) {
			LED_ON(PED_LED_PORT, PED_YLED_PIN);
			LED_ON(CAR_LED_PORT, CAR_YLED_PIN);
		} else if (Pedestrian_Tick == 14) {
			LED_OFF(PED_LED_PORT, PED_YLED_PIN);
			LED_OFF(CAR_LED_PORT, CAR_YLED_PIN);
		} else if (Pedestrian_Tick == 15) {
			LED_ON(PED_LED_PORT, PED_YLED_PIN);
			LED_ON(CAR_LED_PORT, CAR_YLED_PIN);
		} else if (Pedestrian_Tick == 16) {
			LED_OFF(PED_LED_PORT, PED_YLED_PIN);
			LED_OFF(CAR_LED_PORT, CAR_YLED_PIN);
			LED_ON(CAR_LED_PORT, CAR_GLED_PIN);
			LED_ON(PED_LED_PORT, PED_RLED_PIN);
			LED_OFF(PED_LED_PORT, PED_GLED_PIN);

			g_mode = 0;
			//Pedestrian_Tick=0;
			g_pedestrianCheck = 1;
			Pedestrian_State = OK;
		}

	} else if (Color_Flag == RED && isGreen== 0) {
		if (Pedestrian_Tick == 1) {
			LED_OFF(PED_LED_PORT, PED_RLED_PIN);
			LED_ON(PED_LED_PORT, PED_GLED_PIN);
			LED_ON(CAR_LED_PORT, CAR_RLED_PIN);
			isGreen=1;
		} else if (Pedestrian_Tick == 6) {
			LED_OFF(CAR_LED_PORT, CAR_RLED_PIN);
			LED_ON(PED_LED_PORT, PED_YLED_PIN);
			LED_ON(CAR_LED_PORT, PED_YLED_PIN);

		} else if (Pedestrian_Tick == 7) {
			LED_OFF(PED_LED_PORT, PED_YLED_PIN);
			LED_OFF(CAR_LED_PORT, CAR_YLED_PIN);
		} else if (Pedestrian_Tick == 8) {
			LED_ON(PED_LED_PORT, PED_YLED_PIN);
			LED_ON(CAR_LED_PORT, CAR_YLED_PIN);
		} else if (Pedestrian_Tick == 9) {
			LED_OFF(PED_LED_PORT, PED_YLED_PIN);
			LED_OFF(CAR_LED_PORT, CAR_YLED_PIN);
		} else if (Pedestrian_Tick == 10) {
			LED_ON(PED_LED_PORT, PED_YLED_PIN);
			LED_ON(CAR_LED_PORT, CAR_YLED_PIN);
		} else if (Pedestrian_Tick == 11) {
			LED_OFF(PED_LED_PORT, PED_YLED_PIN);
			LED_OFF(CAR_LED_PORT, CAR_YLED_PIN);
			LED_ON(CAR_LED_PORT, CAR_GLED_PIN);
			LED_ON(PED_LED_PORT, PED_RLED_PIN);
			LED_OFF(PED_LED_PORT, PED_GLED_PIN);
			isGreen=0;
			//Pedestrian_Tick=0;
		} else {
			LED_OFF(PED_LED_PORT, PED_RLED_PIN);
			g_mode = 0;
			g_pedestrianCheck = 1;
			Pedestrian_State = OK;
		}
	}
	return Pedestrian_State;
}

/*void TimerDriverTest(void) {
	static uint8_t tick = 0;
	tick++;
	if (tick < 10) {
		LED_ON(CAR_LED_PORT, CAR_GLED_PIN);
		LED_ON(CAR_LED_PORT, CAR_YLED_PIN);
		LED_ON(CAR_LED_PORT, CAR_RLED_PIN);
	} else if (tick >= 10 ) {

		LED_OFF(CAR_LED_PORT, CAR_GLED_PIN);
		LED_OFF(CAR_LED_PORT, CAR_YLED_PIN);
		LED_OFF(CAR_LED_PORT, CAR_RLED_PIN);
	}
}*/

State_Check application_starter(void) {
	Timer_Config Config_PTR;
	State_Check State = OK;
	//Timer_SetCallback(TimerDriverTest);
	if (g_mode == 0 && Normal_State == OK) {
		Timer_SetCallback(Normal_Mode);
	} else if (g_mode == 1 && g_pedestrianCheck) {
		while ((GPIO_readPin(BUTTON_PORT_ID, BUTTON_PIN_ID)))
			;
		Timer_DeInit();
		Config_PTR.starting_value = 0;
		Config_PTR.compare_value = 7812;
		Config_PTR.mode = CTC;
		Config_PTR.prescaler = CLCK_PRESCALER_1024;
		Timer_Init(&Config_PTR);
		Timer_SetCallback(Pedestrian_Mode);
		g_pedestrianCheck = 0;

	}

	return State;

}


