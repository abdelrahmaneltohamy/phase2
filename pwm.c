/*
 * PWM.c
 *
 *  Created on: 02 feb, 2020
 *      Author: Hazem
 */


#include"pwm.h"
#include "motor.h"

void timer1_pwm_init(uint8_t set_duty_cycle)
{
	
	TCNT1L = 0; // Timer initial value
	
	OCR1AL = set_duty_cycle ; //compare value
	OCR1BL =  set_duty_cycle;
	

	SET_BIT(DDRD,PIN4);
	SET_BIT(DDRD, PIN5);
	SET_BIT(TCCR1A, WGM10);
	SET_BIT(TCCR1A, COM1A1);
	SET_BIT(TCCR1A, COM1B1);
	SET_BIT(TCCR1B, WGM12);
	SET_BIT(TCCR1B, CS11);
}
