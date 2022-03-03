/*
 * high_tech_lions.c
 *
 * Created: 2022-02-28 15:40:23
 * Author : ja7516lu-s
 */ 

#include <avr/io.h>


uint8_t lions_in_wild = 0;

void init_sensors() {
	DDRC |= (0<<DDRC6) | (0<<DDRC7);
}

void init_leds() {
	DDRB |= 0xff;
}

uint8_t sens1() {
	return (PINC & (1 << PORTC6)) >> PORTC6;
}

uint8_t sens2() {
	return (PINC & (1 << PORTC7)) >> PORTC7;
}

uint8_t state() {
	return sens1() | (sens2() << 1);
}

void lions() {
	static uint8_t last_state = 0;
	static uint8_t enter_state = 0;
	
	if (state() != last_state) {
		if (last_state == 0) enter_state |= state();
		
		if (state() == 0) {
			// End of sequence
			if (enter_state == 1 && last_state == 2) lions_in_wild--;
			if (enter_state == 2 && last_state == 1) lions_in_wild++;
			enter_state = 0;
		}
		
		last_state = state();
	}
}

int main(void)
{
	init_sensors();
	init_leds();
	
	security_system_init();

	while (1)
	{
		security_system_run();
		lions();
		send_lions(lions_in_wild);
	}
}

