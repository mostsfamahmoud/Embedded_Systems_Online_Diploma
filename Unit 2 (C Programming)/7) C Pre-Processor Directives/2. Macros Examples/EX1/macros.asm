	.file	"macros.c"
	.text
	.def	printf;	.scl	3;	.type	32;	.endef
	.seh_proc	printf
printf:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	leaq	48(%rsp), %rbp
	.seh_setframe	%rbp, 48
	.seh_endprologue
	movq	%rcx, 32(%rbp)
	movq	%rdx, 40(%rbp)
	movq	%r8, 48(%rbp)
	movq	%r9, 56(%rbp)
	leaq	40(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rbx
	movl	$1, %ecx
	movq	__imp___acrt_iob_func(%rip), %rax
	call	*%rax
	movq	%rbx, %r8
	movq	32(%rbp), %rdx
	movq	%rax, %rcx
	call	__mingw_vfprintf
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "Value of height : %d\12\0"
.LC1:
	.ascii "Value of PI : %f\12\0"
.LC2:
	.ascii "Value of Letter : %c\12\0"
.LC3:
	.ascii "ABC\0"
.LC4:
	.ascii "Value of Letter_Seq : %s\12\0"
.LC5:
	.ascii "Value of BackSlash_Char : %c\12\0"
.LC6:
	.ascii "Hello To Learn In Depth\12\0"
.LC7:
	.ascii "val = %x\12\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	call	__main
	movl	$100, %edx
	leaq	.LC0(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movabsq	$4614253070214989087, %rax
	movq	%rax, %rdx
	movq	%rdx, %xmm0
	movapd	%xmm0, %xmm1
	movq	%rax, %rdx
	leaq	.LC1(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movl	$65, %edx
	leaq	.LC2(%rip), %rax
	movq	%rax, %rcx
	call	printf
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdx
	leaq	.LC4(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movl	$92, %edx
	leaq	.LC5(%rip), %rax
	movq	%rax, %rcx
	call	printf
	leaq	.LC6(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movl	$15, -4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, %edx
	leaq	.LC7(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movl	$0, %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (Rev9, Built by MSYS2 project) 11.2.0"
	.def	__mingw_vfprintf;	.scl	2;	.type	32;	.endef
