;
; blinking_led.asm
;
; Created: 2022-02-21 13:53:31
; Author : ja7516lu-s
;


#define PORTB 0x05
#define DDRB 0x04
#define LED1 1
#define decr 138

start:
	call led_init
	call led_toggle
	call delay
	call led_toggle
	call delay
	rjmp start
end:
	rjmp end

	led_init:
		ldi r16, 0b11111111
		out DDRB, r16
	ret

	led_toggle:
		ldi r16, (1 << LED1)
		in r17, PORTB
		eor r16, r17
		out PORTB, r16
	ret

	delay:
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
	ret