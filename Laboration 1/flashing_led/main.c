/*
 * flashing_led.c
 *
 * Created: 2022-01-31 13:42:35
 * Author : ja7516lu-s
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include "yoda.h"
#include <util/delay.h>

int main(void)
{
    unsigned int num = 0;
	led_init();
	
    while (1) 
    {
		led_toggle(num);
		_delay_ms(1000);
    }
	
	return 0;
}

