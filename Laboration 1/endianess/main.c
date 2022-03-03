/*
 * endianness.c
 *
 * Created: 2022-02-10 10:56:04
 * Author : ja7516lu-s
 */ 

#include <avr/io.h>
#include <stdint.h>


void myfunc1(int p)
{
	p++;
}
void myfunc2(int* p)
{
	(*p)++;
}

int main()
{
	
	int a = 2;
	char b = 'A';
	uint8_t c = 2;
	uint16_t d = 300;
	int array[2] = {2,3};
		
	uint8_t num1=0;
	int8_t num2=0;
	
	int i1=1;
	int i2=2;
	int* ptr1=&i1; // pointer declaration
	int* ptr2=&i2;
	ptr1=ptr2;
	i1=*ptr1; // accessing value at address in ptr1
	
	int i=4;
	int*ptr=&i;
	
    while (1) 
    {
		a = 2;
		
		num1--;
		num2--;
		
		myfunc1(*ptr);
		myfunc2(ptr);
    }
}

