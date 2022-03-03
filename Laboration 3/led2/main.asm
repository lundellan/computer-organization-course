;
; led2.asm
;
; Created: 2022-02-21 13:46:13
; Author : ja7516lu-s
;


#define PORTB 0x05
#define DDRB 0x04
#define LED2 2

start:
	ldi r16, 0b11111111
	out DDRB, r16
	ldi r16, (1 << LED2)
	out PORTB, r16
end:
	rjmp end