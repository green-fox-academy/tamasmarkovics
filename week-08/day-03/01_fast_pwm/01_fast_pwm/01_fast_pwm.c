#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>
#include "pwm.h"


int main(void)
{
	uint8_t duty = 50;
	init(PHASE_CORRECT);
    while(1)
    {
        set_duty(duty);
        _delay_ms(50);
        duty += 1;
        
        if (duty >= 100)
        {
            duty = 0;
        }
    }
}