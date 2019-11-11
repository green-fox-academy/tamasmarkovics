#include <avr/io.h>


void init()
{
	//Set PWM out on PD6
	DDRD = 0b01000000;
	//Set timer control register A - fast PWM
	TCCR0A = 0b10000011;
	//Set timer 0 pre-scaler
	TCCR0B = 0b00000010;
	
	//Set ADC Enable
	ADCSRA = 0b11100011;
	//Set left adjust
	ADMUX = 0b00100000;
}

void set_duty()
{
	OCR0A = ADCH;
}

int main(void)
{
	init();
	
    while (1) 
    {
		set_duty();
	}
}
