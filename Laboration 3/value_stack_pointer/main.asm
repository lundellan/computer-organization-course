;
; value_stack_pointer.asm
;
; Created: 2022-02-21 14:21:37
; Author : ja7516lu-s
;


#define STACK_H 0x3E
#define STACK_L 0x3D
#define N_ALLOC 5

start:
	call allocate
end:
    rjmp end

    allocate:
		in r28, STACK_L
		in r29, STACK_H
		sbiw Y, N_ALLOC
		out STACK_L, r28
		out STACK_H, r29 ; end of prologue
		in r28, STACK_L
		in r29, STACK_H
		adiw Y, 10
		out STACK_L, r28
		out STACK_H, r29
    ret