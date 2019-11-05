#include <avr/io.h>
#include <stdint.h>

void init()
{
	// Set the prescaler to 1024 division. See at the TC0 control register in the datasheet!
	// With this you also set the clock source to CLK_io and you will also turn on the timer!
	TCCR0B = 0b00000101;
	// Set the PB5 LED pin to output
	DDRB = 0b00101111;
}

int main(void)
{
	// Create a variable which will be a counter variable, initialize it with 0.
	volatile uint8_t count = 0;
	// This will be the maximal value of our counter
	uint8_t cntr_max = 30;

	// Don't forget to call the init function!
	init();
	// Your task is to create about 1Hz flashing LED with the TC0 timer.
	// Use the counter variable, cntr_max and the overflow flag as a hint.
	
	while (1)
	{
		if ((TIFR0 & 0b00000001) == 0b00000001) {
			count++;
			TIFR0 = 0b00000001;
		}

		if (count == cntr_max) {
			PINB = 0b0101111;
			count = 0;
		}
	}
}