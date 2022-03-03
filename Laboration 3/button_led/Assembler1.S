
/*
 * Assembler1.S
 *
 * Created: 2022-02-23 15:09:04
 *  Author: ja7516lu-s
 */ 

#define STACK_H 0x3E
#define STACK_L 0x3D
#define PORTB 0x05
#define DDRB 0x04
#define DDRA 0x01
#define PINA 0x00
#define decr 138

.global led_init
.global button_init
.global led_on
.global led_off
.global check_button

led_init:
    ldi r18, 0b11111111
    out DDRB, r18
ret

led_on:
    ldi r18, 1				; Load 0b00000001 to r18

    loop_on:
        lsl r18				; Left shift r18
        dec r24				; Decrement r24 (the passed argument)
        brne loop_on

	or r18, PORTB			; r18 = r18 | PORTB
    out PORTB, r18			; Set PORTB to r18
ret

led_off:
    ldi r18, 0				; Load 0b00000000 to r18

    loop_off:
        lsl r18				; Left shift r18
        dec r24				; Decrement r24 (the passed argument)
        brne loop_off

	or r18, PORTB			; r18 = r18 | PORTB
    out PORTB, r18
ret

button_init:
    ldi r18, 0b00000000
    out DDRA, r18
ret

check_button:
	in r18, PINA			; Load PINA value to r18
	ldi r19, 1			; Load a one to r19
	lsr r18				; Right shift r18

	loop_btn:
		lsr r18			; Right shift r18
		dec r24			; Decrement r24 (the passed argument)
		brne loop_btn

	and r18, r19			; r18 = r18 & r19
	cpi r18, 1			; Compare r18 and 1
	breq pressed			; Branch to pressed if equal

	ldi r24, 0			; Return 0
	ret

	pressed:
		ldi r24, 1		; Return 1
		ret