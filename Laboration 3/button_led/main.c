/*
 * button_led.c
 *
 * Created: 2022-02-23 15:07:07
 * Author : ja7516lu-s
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

extern void led_init();
extern void button_init();
extern void led_on(char);
extern void led_off(char);
extern char check_button(char);

int main(void)
{
	led_init();
	button_init();
	
	int led = 1;
	int button = 1;
	
	while (1)
	{
		if (check_button(button)) {
			led_on(led);
			_delay_ms(500);
			led_off(led);
			_delay_ms(500);
		}
	}
}
