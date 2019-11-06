#include "pwm.h"
#include <avr/io.h>

void init(pwm_type_t type)
{
	if (type == FAST) {
		TCCR0A = 0b10000011;
} else TCCR0A = 0b10000001;
	TCCR0B = 0b00000100;
	DDRD = 1 << 6;
	OCR0A = 100;
}

void set_duty(uint8_t duty) {
	OCR0A = duty * 255 / 100;
}