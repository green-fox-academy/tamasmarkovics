#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000
#include <util/delay.h>

uint8_t duty = 0;
uint8_t dir = 0;

void init()
{
	//Set OC0A (Timer0 compare) as output
	DDRD = 0b01000000;
	//Set Timer0 control register A - fast pwm
	TCCR0A = 0b10000011;
	//Set Timer0 pre-scaler
	TCCR0B = 0b00000010;
	
	//Set Timer2
	//Set OCF2A
	TIFR2 = 0b00000001;
	TCCR2B = 0b00000111;
	TIMSK2 = 0b00000001;
	sei();
	
	//
}

void set_duty(uint8_t duty)
{
	OCR0A = (duty * 255) / 100;
}

ISR(TIMER2_OVF_vect)
{
	if (dir) {
		duty -= 1;
		} else {
		duty += 1;
	}
	if (duty >= 100) {
		duty = 100;
		dir = 1;
		} else if (duty <= 0) {
		duty = 0;
		dir = 0;
	}
	set_duty(duty);
	TIFR2 = 0b00000001;
}

int main(void)
{
	init();
	
	while (1)
	{
		
	}
}
