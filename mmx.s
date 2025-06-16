section .data
	a_values db 1,  2,  3,  4,  5
	b_values db 10, 20, 30, 40, 50
	result   db 0,  0,  0,  0,  0

section .text
global _start

_start:
	; Load from 64-bit register into MMX register
	; mm0 = [1, 2, 3, 4, ...]
	; mm1 = [10, 20, 30, 40, ...]
	movq mm0, [a_values]
	movq mm1, [b_values]

	; Byte addition, no saturate
	; mm0 = mm0 + mm1
	paddb mm0, mm1

	; Write to the `result`
	movq [result], mm0

	; Erase MMX Technology State, mandatory to clean FPU
	emms

	; syscall, exit
	mov eax, 60
	xor edi, edi
	syscall

