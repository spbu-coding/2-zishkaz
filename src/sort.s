	.file	"sort.c"
	.text
	.globl	choose_sort
	.type	choose_sort, @function
choose_sort:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movl	%esi, %eax
	addq	%rax, %rax
	addq	$16, %rax
	shrq	$4, %rax
	salq	$4, %rax
	subq	%rax, %rsp
	xorl	%eax, %eax
	movq	%rsp, %rcx
.L2:
	cmpl	%eax, %esi
	jbe	.L16
	movw	$0, (%rcx,%rax,2)
	incq	%rax
	jmp	.L2
.L16:
	leal	-1(%rsi), %r10d
	xorl	%eax, %eax
.L4:
	cmpl	%eax, %r10d
	movl	%eax, %r11d
	jbe	.L17
	leaq	1(%rax), %r9
	movl	%eax, %edx
	movq	%r9, %r8
.L5:
	cmpl	%r8d, %esi
	jbe	.L18
	movslq	%edx, %rbx
	movq	(%rdi,%rbx,8), %rbx
	cmpq	%rbx, (%rdi,%r8,8)
	cmovl	%r8d, %edx
	incq	%r8
	jmp	.L5
.L18:
	cmpl	%edx, %r11d
	je	.L8
	movslq	%edx, %rdx
	incw	(%rcx,%rax,2)
	leaq	(%rdi,%rdx,8), %r8
	incw	(%rcx,%rdx,2)
	movq	(%rdi,%rax,8), %rdx
	xorq	(%r8), %rdx
	movq	%rdx, (%rdi,%rax,8)
	xorq	(%r8), %rdx
	movq	%rdx, (%r8)
	xorq	%rdx, (%rdi,%rax,8)
.L8:
	movq	%r9, %rax
	jmp	.L4
.L17:
	xorl	%edx, %edx
	xorl	%eax, %eax
.L10:
	cmpl	%edx, %esi
	jbe	.L19
	cmpw	$0, (%rcx,%rdx,2)
	jle	.L11
	incl	%eax
.L11:
	incq	%rdx
	jmp	.L10
.L19:
	movq	-24(%rbp), %rbx
	xorq	%fs:40, %rbx
	je	.L13
	call	__stack_chk_fail@PLT
.L13:
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	choose_sort, .-choose_sort
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
