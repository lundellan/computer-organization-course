/*
 * home_assignment_2.c
 *
 * Created: 2022-02-08 11:20:23
 * Author : ja7516lu-s
 */ 

#include <avr/io.h>
#include <stdio.h>


int main(void)
{
    int* ddrA = 0x21;
	int* pinA = 0x20;
	
	// Data direction is set to in for all buttons on Port A
	*ddrA |= 0b00000000;
	
	while (1) {
		// Checks if button 4 (index 5) is pressed
		if (*pinA == 0b00010000)	{
			// Logic for what you want to happen when it is pressed
		}
	}
	
}

