/*
 * extra_button_reliable.c
 *
 * Created: 2022-02-09 10:55:50
 * Author : ja7516lu-s
 */ 

#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>

uint8_t* init_leds()
{
	// Sets data direction to out for all leds
	DDRB |= 0b11111111;
}

uint8_t* init_buttons()
{
	// Sets data direction to in for the extra button
	DDRD |= 0<<DDRD7;
}

uint8_t button_read_reliably()	
{
	volatile uint8_t button_state = (PIND & 1<<PIND7)>>PIND7;
	
	if (button_state & 1)	
	{
		_delay_ms(15);
		
		button_state = (PIND & 1<<PIND7)>>PIND7;
		
		if (button_state & 1) return 1;
	}
	
	return 0;
}

int main(void)
{
	init_leds();
	init_buttons();
	
	while (1)
	{
		if (button_read_reliably())	{
			PORTB ^= 1;
			
			while (button_read_reliably());
		}
	}
}

