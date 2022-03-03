;
; state_saver.asm
;
; Created: 2022-02-23 14:59:45
; Author : ja7516lu-s
;


; Replace with your application code
#define STACK_H 0x3E
#define STACK_L 0x3D
#define N_ALLOC 5
#define DDRA 0x01
#define PINA 0x00

start:
	call button_init

	infinite:
		call subroutine
		rjmp infinite
end:
    rjmp end

	button_init:
		push r16			; Save r16 value in stack
		ldi r16, 0b00000000		; Load 0b00000000 into r16
        out DDRA, r16				; Set DDRA to r16
		pop r16				; Return r16 to initial value
		ret

    subroutine:
		// Prologue
		push r16			; Save r16 value in stack
		push r17			; Save r17 value in stack
		push r18			; Save r18 value in stack
		push r24			; Save r24 value in stack

		in r28, STACK_L			; Load pointer low to r28
		in r29, STACK_H			; Load pointer high to r29
		sbiw Y, N_ALLOC			; Subtract memory allocation value from Y
		out STACK_L, r28		; Set stack low to r28
		out STACK_H, r29		; Set stack high to r29

		// Body
		ldi r24, N_ALLOC		; Set r24 to memory allocation value

		loop:
			in r18, PINA		; Load PINA to r18
			st Y, r18		; Write r18 to address Y
			adiw Y, 1		; Add 1 to local pointer (Y)
			dec r24			; Decrement r24
			brne loop

		// Epilogue
		in r28, STACK_L			; Load stack low into r28
		in r29, STACK_H			; Load stack high into r29
		adiw Y, N_ALLOC			; Add memory allocation value to Y
		out STACK_L, r28		; Set stack low to r28
		out STACK_H, r29		; Set stack high to r29

		pop r24				; Return r24 to initial value
		pop r18				; Return r18 to initial value
		pop r17				; Return r17 to initial value
		pop r16				; Return r16 to initial value
