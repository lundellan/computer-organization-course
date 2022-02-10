/*
 * macros.c
 *
 * Created: 2022-02-09 10:13:49
 * Author : ja7516lu-s
 */ 

#include <avr/io.h>
#include <stdint.h>

uint8_t* init_leds()
{
	// Sets data direction to out for all leds
	DDRB |= 0b11111111;
}

uint8_t* init_buttons()
{	
	// Sets data direction to in for all buttons
	DDRD |= 0<<DDRD7;
}

int main(void)
{
	init_leds();
	init_buttons();
	
	while (1)
	{
		// Input to extra button
		volatile uint8_t button_state = PIND & 1<<PIND7;
		
		// Output to leds
		PORTB ^= button_state >> 1;
		
		while ((PIND & 1<<PIND7) == button_state);
	}
}