#include <avr/io.h>
#include <stdint.h>
#include <avr/interrupt.h>

// Create a variable which will be a counter variable, initialize it with 0. This time it has to be global.
// This will be the maximal value of our counter. This time it has to be global.
uint8_t cntr = 0;
const uint8_t cntr_max = 10;

// Write here the interrupt handler function. The vector name starts with TIMER ;). Use Ctrl+Space to find the proper vector name!
ISR (TIMER0_OVF_vect)
{
	cntr++;
	//overflow interrupt flag
	TIFR0 = 0b00000001;
	if (cntr == cntr_max) {
		PINB = 0b00100000; //PB5 LED ON
		cntr = 0;		   //STARTS OVER
	}
}
// Do the same thing in the interrupt handler as before.
// This time you don't have to do anything with the flags, the MCU does it automatically.

void init()
{
	// Set the prescaler to 1024 division. See at the TC0 control register in the datasheet!
	// With this you also set the clock source to CLK_io and you will also turn on the timer!
	TCCR0B = 0b00000101;  //prescaler
	// Set the PB5 LED pin to output
	DDRB = 0b00100000;
	// Enable the TC0 overflow interrupt
	PCICR = 0b00000100;	
	TIMSK0 = 0b00000001;
	// Enable the interrupts globally
	sei();
}

int main(void)
{
	// Don't forget to call the init function!
	init();
	
	while (1)
	{
		//Nothing to do here, everything is done in interrupt :)
	}
}