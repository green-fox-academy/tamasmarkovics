#include "TC74_driver.h"
#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>

#define F_CPU 16000000UL
#include <avr/delay.h>

#define LED_DDR			DDRB
#define LED_DDR_POS		DDRB5
#define LED_PIN			PINB
#define LED_PIN_POS		PINB5
#define LED_PORT		PORTB
#define LED_PORT_POS	PORTB5

void system_init()
{
	//TODO
	// Call the TWI driver init function
	TWI_init();

	// SDIO lib is initialed with 115200 baud rate with 8N1 settings

	// Interrupts must be enabled as STDIO lib uses interrupts for receive
	sei();
}

int main(void)
{
	// Don't forget to call the init function :)
	system_init();

	printf("System initialized\n");
	
	int8_t temperature = 0;
	
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);					//STARTS I2C
	while(!(TWCR & 1 << TWINT));										//WAIT FOR RESPONSE
	TWDR = 0b10010000;													//SEND ADDRESS
	TWCR = (1 << TWINT) | (1 << TWEN);									//WAIT FOR RESPONSE
	while(!(TWCR & 1 << TWINT));										//WAIT FOR RESPONSE
	TWDR = 0;
	TWCR = (1 << TWINT) | (1 << TWEN);
	while(!(TWCR & 1 << TWINT));
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
	while(!(TWCR & 1 << TWINT));
	TWDR = 0b10010001;
	TWCR = (1 << TWINT) | (1 << TWEN);
	while(!(TWCR & 1 << TWINT));
	TWCR |= 1 << TWINT;
	temperature = TWDR;
	TWCR = (1 << TWINT) | (1 << TWEN) | ( 1 << TWSTO);
	
	// Infinite loop
	while (1) {


	}
}