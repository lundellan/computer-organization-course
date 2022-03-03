;
; allocate_10_integers.asm
;
; Created: 2022-02-21 14:18:12
; Author : ja7516lu-s
;


start:
    call prologue
	/* Code to be executed */
	call epilogue

prologue:
	in r28, STACK_L
	in r29, STACK_H
	sbiw Y, 10
	out STACK_L, r28
	out STACK_H, r29
ret

epilogue:
	in r28, STACK_L
	in r29, STACK_H
	sbiw Y, 10
	out STACK_L, r28
	out STACK_H, r29
ret