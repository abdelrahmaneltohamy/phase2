#include "motor.h"
#include "pwm.h"
#include <avr/delay.h>
int main(void)
{
	Motor_init();
	Motor_move_forward();
	while(1)
	{
		//_delay_ms(3000);
		//timer1_pwm_init(128);
		//_delay_ms(3000);
		timer1_pwm_init(255);
	}
}
