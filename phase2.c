/*
 * main.c
 *
 *  Created on: Feb 2, 2020
 *      Author: Hatem
 */

#include "ultrasonic.h"
#include "motor.h"
#include "timer.h"
#include "pwm.h"

extern volatile uint8_t g_tick;
extern volatile uint16_t Distance;

int main()
{
	Ultrasonic_init();
	uint8_t state=1;
	Ultrasonic_en_interrupt();
	SET_BIT(DDRB, PIN4);
	SET_BIT(DDRB, PIN5);
	Motor_init();
	Motor_move_forward();
	timer1_pwm_init(128);
	while(1)
	{
		if(g_tick == 0)
		{
			Ultrasonic_start();
			g_tick = 1;
		}
		if(Distance < 100 && state==1)
		{
			timer1_pwm_init(192);
			while(Distance<100);
			state=2;
		}
		else if(Distance<100 && state==2)
		{
			timer1_pwm_init(255);
			while(Distance<100);
			state=3;
		}
		if(Distance<10 && state==3)
		{
			timer1_pwm_init(0);

		}
	}
}
