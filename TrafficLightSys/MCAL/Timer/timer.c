/*
 * timer.c
 *
 *  Created on: 30 Dec 2022
 *      Author: Aly Tarek
 */

#include"timer.h"
#include<avr/interrupt.h>
#include<avr/io.h>


/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/
static volatile void (*g_CallB_ptr)(void) =  NULL_PTR;


/*******************************************************************************
 *                                   ISR's                                     *
 *******************************************************************************/
ISR (TIMER1_OVF_vect){
	if(g_CallB_ptr!= NULL_PTR){
		(*g_CallB_ptr)();

	}
}

ISR (TIMER1_COMPA_vect){
	if(g_CallB_ptr!= NULL_PTR){
		(*g_CallB_ptr)();


	}
}

/*******************************************************************************
 *                         Functions Defin                                     *
 *******************************************************************************/

void Timer_Init(Timer_Config *Config_PTR){
	/*
	 * -Configuring Timer registers to work as specified in rubric
	 * -Inserting prescaler data to the register
	 * -Adding starting value and Compare value to their registers
	 * -Enabling Interrupt for compare match
	 */

	TCCR1A = (1 << FOC1A) | (1 << FOC1B);
	CLEAR_BIT(TCCR1B, WGM13);
	//TCCR1B = ~(1<<WGM13);

	TCCR1B = (1<<WGM12);//Setting Compare MODE

	TCCR1B = (TCCR1B & 0xf8) | ((Config_PTR->prescaler) & 0x07);

	TCNT1= Config_PTR->starting_value;

	OCR1A = Config_PTR->compare_value;

	TIMSK = (1<<OCIE1A);


}

void Timer_SetCallback(void(*call_ptr)(void)){
	/*
	 * The whole function just saves the address
	 * of the Call back function in the Global PTR
	 */
	g_CallB_ptr=call_ptr;
}

void Timer_DeInit(void){
	/*
	 * Function Stops timer by clearing it's registers
	 * such as clearing the starting value and compare value
	 * and disabling the interrupt compare register
	 */
	TCCR1A=0;
	TCCR1B=0;
	TCNT1=0;
	OCR1A=0;
	TIMSK &= ~(1<<OCIE1A);
}

void INT0_Init(void) {
	SET_BIT(MCUCR, ISC01);
	SET_BIT(MCUCR, ISC00);
	SET_BIT(GICR, INT0);
}


