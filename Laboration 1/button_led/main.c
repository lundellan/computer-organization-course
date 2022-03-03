/*
 * button_led.c
 *
 * Created: 2022-01-31 14:13:05
 * Author : ja7516lu-s
 */ 

#include <avr/io.h>
#include "yoda.h"

uint8_t count = 3;

int main(void)
{
	
	led_init();
	button_init();
	
    while (1) 
    {
		if (button_read(1))	
		{
			if (count < 0) led_toggle(0);
			
			while (1)	
			{
				if (!button_read(1)) break;
			}
			
			count--;
		}
	}
}

