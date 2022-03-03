/*
 * interrupt_counter.c
 *
 * Created: 2022-03-03 15:19:58
 * Author : ja7516lu-s
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint8_t counter = 0;

void init_sensors() {
	DDRC |= (0<<DDRC6) | (0<<DDRC7);
}

void init_interrupt() {
	PCMSK2 |= (1<<PCINT22) | (1<<PCINT23);
	PCICR |= 1<<PCIE2;
}

int main(void)
{
	init_sensors();
	init_interrupt();
	sei();

	while (1)
	{
	}
}

ISR(PCINT2_vect)
{
	counter++;
}

