section .data
	a_values db 1,  2,  3,  4
	b_values db 10, 20, 30, 40
	result   db 0, 0, 0, 0

section .text
global _start

_start:
	mov al, [a_values]
	add al, [b_values]
	mov [result], al

	mov al, [a_values+1]
	add al, [b_values+1]
	mov [result+1], al

	mov al, [a_values+2]
	add al, [b_values+2]
	mov [result+2], al

	mov al, [a_values+3]
	add al, [b_values+3]
	mov [result+3], al

	mov eax, 60
	xor edi, edi
	syscall

