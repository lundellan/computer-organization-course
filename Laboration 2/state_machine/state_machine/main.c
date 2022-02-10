/*
 * state_machine.c
 *
 * Created: 2022-02-09 10:05:30
 * Author : ja7516lu-s
 */ 

#include <avr/io.h>
#include <stdint.h>

uint8_t* init_leds()
{
	// Reference to DDRB
	volatile uint8_t* ddrB = 0x24;
	
	// Sets data direction to out for all leds
	*ddrB |= 0b11111110;
	
	// Returns the reference to PORTB
	return 0x25;
}

uint8_t* init_buttons()
{
	// Reference to DDRA
	volatile uint8_t* ddrA = 0x21;
	
	// Sets data direction to in for all buttons
	*ddrA |= 0b00000000;
	
	// Returns the reference to PINA
	return 0x20;
}

int main(void)
{
    volatile uint8_t* leds = init_leds();
	volatile uint8_t* buttons = init_buttons();
	
    while (1) 
    {
		volatile uint8_t button_state = *buttons;
		
		*leds ^= button_state >> 1;
		
		while (*buttons == button_state);
    }
}

