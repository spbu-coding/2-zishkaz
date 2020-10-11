	.file	"choose_sort.c"
	.text
	.globl	_choose_sort
	.def	_choose_sort;	.scl	2;	.type	32;	.endef
_choose_sort:
LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$28, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	movl	12(%ebp), %eax
	movl	8(%ebp), %edx
	addl	%eax, %eax
	movl	%eax, -32(%ebp)
	addl	$15, %eax
	shrl	$4, %eax
	sall	$4, %eax
	call	___chkstk_ms
	subl	%eax, %esp
	xorl	%eax, %eax
	movl	%esp, -28(%ebp)
L2:
	cmpl	12(%ebp), %eax
	je	L15
	movl	-28(%ebp), %esi
	movw	$0, (%esi,%eax,2)
	incl	%eax
	jmp	L2
L15:
	movl	12(%ebp), %eax
	xorl	%ebx, %ebx
	decl	%eax
	movl	%eax, -36(%ebp)
L4:
	cmpl	%ebx, -36(%ebp)
	jbe	L16
	leal	1(%ebx), %esi
	movl	%ebx, %eax
	movl	%esi, %ecx
L5:
	cmpl	%ecx, 12(%ebp)
	jbe	L17
	movl	(%edx,%eax,8), %edi
	cmpl	%edi, (%edx,%ecx,8)
	movl	4(%edx,%ecx,8), %edi
	sbbl	4(%edx,%eax,8), %edi
	jge	L6
	movl	%ecx, %eax
L6:
	incl	%ecx
	jmp	L5
L17:
	cmpl	%eax, %ebx
	je	L8
	movl	-28(%ebp), %ebx
	incw	-2(%ebx,%esi,2)
	incw	(%ebx,%eax,2)
	leal	(%edx,%eax,8), %eax
	movl	(%eax), %ecx
	movl	4(%eax), %ebx
	addl	-8(%edx,%esi,8), %ecx
	adcl	-4(%edx,%esi,8), %ebx
	movl	%ecx, -8(%edx,%esi,8)
	movl	%ebx, -4(%edx,%esi,8)
	subl	(%eax), %ecx
	sbbl	4(%eax), %ebx
	movl	%ecx, (%eax)
	movl	%ebx, 4(%eax)
	subl	%ecx, -8(%edx,%esi,8)
	sbbl	%ebx, -4(%edx,%esi,8)
L8:
	movl	%esi, %ebx
	jmp	L4
L16:
	movl	-28(%ebp), %edi
	movl	-32(%ebp), %edx
	xorl	%eax, %eax
	addl	%edi, %edx
L10:
	cmpl	%edx, %edi
	je	L18
	cmpw	$0, (%edi)
	jle	L11
	incl	%eax
L11:
	addl	$2, %edi
	jmp	L10
L18:
	leal	-12(%ebp), %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%edi
	.cfi_restore 7
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE0:
	.ident	"GCC: (MinGW.org GCC Build-2) 9.2.0"
