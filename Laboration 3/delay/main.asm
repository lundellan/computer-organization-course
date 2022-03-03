;
; delay.asm
;
; Created: 2022-02-21 13:33:28
; Author : ja7516lu-s
;


#define PORTB 0x05
#define DDRB 0x04
#define LED0 0
#define LED3 3
#define decr 81

start:
	ldi r16, 0b11111111
	out DDRB, r16
	ldi r16, (1 << LED0)
	out PORTB, r16
	ldi r20, decr
	l1:
		ldi r21, decr
		l2:
			ldi r22, decr
			l3:
				dec	r22
				brne l3
				dec r21
				brne l2
				dec r20
				brne l1
	ldi r16, (1 << LED3)
	in	r17, PORTB
	or	r16, r17
	out PORTB, r16
end:
	rjmp end
