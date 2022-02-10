/*
 * home_assignment_1.c
 *
 * Created: 2022-02-08 10:54:01
 * Author : ja7516lu-s
 */ 

#include <avr/io.h>


int main(void)
{
    int* ddrB = 0x24;
    int* porB = 0x25;
	
	// Data direction is set to out
	*ddrB |= 0b00001000;
	
	// Value of port 3 (index 4) is set to 1
	*porB |= 0b00001000;
		
}

