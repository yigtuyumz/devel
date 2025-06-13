	.file	"aaaa.c"
	.text
	.p2align 4
	.globl	mmx_add
	.type	mmx_add, @function
mmx_add:
.LFB129:
	.cfi_startproc
	endbr64
	movq	%rdi, %r8
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movq	%rdx, %rdi
	movq	%rsi, %rcx
	movzwl	6(%r8), %eax
	movzwl	4(%r8), %edx
	salq	$16, %rax
	orq	%rdx, %rax
	movzwl	2(%r8), %edx
	salq	$16, %rax
	orq	%rdx, %rax
	movzwl	(%r8), %edx
	salq	$16, %rax
	orq	%rdx, %rax
	movzwl	6(%rsi), %edx
	movzwl	4(%rsi), %esi
	movq	%rax, %xmm0
	movl	$1, %eax
	salq	$16, %rdx
	orq	%rsi, %rdx
	movzwl	2(%rcx), %esi
	movzwl	(%rcx), %ecx
	salq	$16, %rdx
	orq	%rsi, %rdx
	salq	$16, %rdx
	orq	%rcx, %rdx
	movq	%rdx, %xmm1
	paddw	%xmm1, %xmm0
	call	_mm_store_si64@PLT
	emms
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE129:
	.size	mmx_add, .-mmx_add
	.p2align 4
	.globl	sum
	.type	sum, @function
sum:
.LFB130:
	.cfi_startproc
	endbr64
	movsbl	a(%rip), %eax
	movsbl	b(%rip), %edx
	addl	%edx, %eax
	ret
	.cfi_endproc
.LFE130:
	.size	sum, .-sum
	.globl	b
	.data
	.type	b, @object
	.size	b, 1
b:
	.byte	10
	.globl	a
	.type	a, @object
	.size	a, 1
a:
	.byte	5
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
