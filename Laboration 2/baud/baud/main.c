/*
 * baud.c
 *
 * Created: 2022-02-09 11:14:46
 * Author : ja7516lu-s
 */ 

#include <avr/io.h>
#include <stdint.h>


void usart0_init()	
{
	// Set baud rate
	UBRR0 = 416;
	
	// Enable transmitter and receiver
	UCSR0B = 0b00011000;	
	
	// Set config
	UCSR0C = 0b00000110;
}

uint8_t usart0_receive()
{
	// Wait until RSX bit becomes 1, meaning that the receiver is finished
	while (!(UCSR0A & 0b10000000));
	return UDR0;	
}

void usart0_transmit(uint8_t data)
{
	// Wait until UDRE bit becomes 1, meaning that its ready to transmit
	while (!(UCSR0A & 0b00100000));
	UDR0 = data;
	
	// Wait until TXC bit becomes 1, meaning that the transmission is complete
	while (!(UCSR0A & 0b01000000));
}

uint8_t* led_init()
{
	volatile uint8_t* ddrB = 0x24;
	*ddrB |= 0b11111111;
	return 0x25;
}

int main(void)
{
	volatile uint8_t* leds = led_init();
	
	usart0_init();
	
    while (1) 
    {
		uint8_t msg = usart0_receive();
		if (msg == 0xF)	{
			*leds ^= 1;
		}
		usart0_transmit(msg);
    }
}

