	.file	"parole.c"
	.text
	.section	.rodata
.LC0:
	.string	"%s"
	.text
	.globl	termina
	.type	termina, @function
termina:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	call	__errno_location@PLT
	movl	(%rax), %eax
	cmpl	$1, %eax
	jne	.L2
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	perror@PLT
	jmp	.L3
.L2:
	movq	-8(%rbp), %rax
	leaq	.LC0(%rip), %rdx
	movq	%rax, %rsi
	movq	%rdx, %rdi
	movl	$0, %eax
	call	printf@PLT
.L3:
	movl	$1, %edi
	call	exit@PLT
	.cfi_endproc
.LFE6:
	.size	termina, .-termina
	.globl	create_coppia
	.type	create_coppia, @function
create_coppia:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movl	%esi, -24(%rbp)
	movl	$8, %edi
	call	malloc@PLT
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	-20(%rbp), %edx
	movl	%edx, (%rax)
	movq	-8(%rbp), %rax
	movl	-24(%rbp), %edx
	movl	%edx, 4(%rax)
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	create_coppia, .-create_coppia
	.globl	numOfHastag
	.type	numOfHastag, @function
numOfHastag:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -40(%rbp)
	movl	$0, -24(%rbp)
	movl	$0, -20(%rbp)
	jmp	.L7
.L9:
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	cmpb	$35, %al
	jne	.L8
	addl	$1, -24(%rbp)
.L8:
	addl	$1, -20(%rbp)
.L7:
	movl	-20(%rbp), %eax
	movslq	%eax, %rbx
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	cmpq	%rax, %rbx
	jb	.L9
	movl	-24(%rbp), %eax
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	numOfHastag, .-numOfHastag
	.globl	destroyarrcoppia
	.type	destroyarrcoppia, @function
destroyarrcoppia:
.LFB9:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L12
.L13:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	free@PLT
	addl	$1, -4(%rbp)
.L12:
	movl	-4(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jl	.L13
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	destroyarrcoppia, .-destroyarrcoppia
	.globl	destroyarrstring
	.type	destroyarrstring, @function
destroyarrstring:
.LFB10:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L15
.L16:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	free@PLT
	addl	$1, -4(%rbp)
.L15:
	movl	-4(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jl	.L16
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	destroyarrstring, .-destroyarrstring
	.globl	mergeStringhe
	.type	mergeStringhe, @function
mergeStringhe:
.LFB11:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$72, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -56(%rbp)
	movl	%esi, -60(%rbp)
	movq	%rdx, -72(%rbp)
	movl	%ecx, -64(%rbp)
	movl	-60(%rbp), %edx
	movl	-64(%rbp), %eax
	addl	%edx, %eax
	cltq
	salq	$3, %rax
	movq	%rax, %rdi
	call	malloc@PLT
	movq	%rax, -24(%rbp)
	movl	$0, -40(%rbp)
	movl	$0, -36(%rbp)
	movl	$0, -32(%rbp)
	jmp	.L18
.L22:
	movl	-40(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-56(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movq	%rax, %rbx
	movl	-36(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-72(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	cmpq	%rax, %rbx
	jnb	.L19
	movl	-40(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-56(%rbp), %rax
	addq	%rdx, %rax
	movl	-32(%rbp), %edx
	movslq	%edx, %rdx
	leaq	0(,%rdx,8), %rcx
	movq	-24(%rbp), %rdx
	addq	%rcx, %rdx
	movq	(%rax), %rax
	movq	%rax, (%rdx)
	addl	$1, -40(%rbp)
	jmp	.L20
.L19:
	movl	-36(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-72(%rbp), %rax
	addq	%rdx, %rax
	movl	-32(%rbp), %edx
	movslq	%edx, %rdx
	leaq	0(,%rdx,8), %rcx
	movq	-24(%rbp), %rdx
	addq	%rcx, %rdx
	movq	(%rax), %rax
	movq	%rax, (%rdx)
	addl	$1, -36(%rbp)
.L20:
	addl	$1, -32(%rbp)
.L18:
	movl	-40(%rbp), %eax
	cmpl	-60(%rbp), %eax
	je	.L23
	movl	-36(%rbp), %eax
	cmpl	-64(%rbp), %eax
	jne	.L22
	jmp	.L23
.L26:
	movl	-40(%rbp), %eax
	cmpl	-60(%rbp), %eax
	je	.L24
	movl	-40(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-56(%rbp), %rax
	addq	%rdx, %rax
	movl	-32(%rbp), %edx
	movslq	%edx, %rdx
	leaq	0(,%rdx,8), %rcx
	movq	-24(%rbp), %rdx
	addq	%rcx, %rdx
	movq	(%rax), %rax
	movq	%rax, (%rdx)
	addl	$1, -40(%rbp)
	jmp	.L25
.L24:
	movl	-36(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-72(%rbp), %rax
	addq	%rdx, %rax
	movl	-32(%rbp), %edx
	movslq	%edx, %rdx
	leaq	0(,%rdx,8), %rcx
	movq	-24(%rbp), %rdx
	addq	%rcx, %rdx
	movq	(%rax), %rax
	movq	%rax, (%rdx)
	addl	$1, -36(%rbp)
.L25:
	addl	$1, -32(%rbp)
.L23:
	movl	-60(%rbp), %edx
	movl	-64(%rbp), %eax
	addl	%edx, %eax
	cmpl	%eax, -32(%rbp)
	jl	.L26
	movl	$0, -28(%rbp)
	jmp	.L27
.L28:
	movl	-28(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	-28(%rbp), %edx
	movslq	%edx, %rdx
	leaq	0(,%rdx,8), %rcx
	movq	-56(%rbp), %rdx
	addq	%rcx, %rdx
	movq	(%rax), %rax
	movq	%rax, (%rdx)
	addl	$1, -28(%rbp)
.L27:
	movl	-28(%rbp), %eax
	cmpl	-32(%rbp), %eax
	jl	.L28
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
	nop
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	mergeStringhe, .-mergeStringhe
	.globl	mergeSortStringhe
	.type	mergeSortStringhe, @function
mergeSortStringhe:
.LFB12:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	cmpl	$1, -28(%rbp)
	je	.L32
	movl	-28(%rbp), %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	movl	%eax, -8(%rbp)
	movl	-28(%rbp), %eax
	subl	-8(%rbp), %eax
	movl	%eax, -4(%rbp)
	movl	-8(%rbp), %edx
	movq	-24(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	mergeSortStringhe
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-24(%rbp), %rax
	addq	%rax, %rdx
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	movq	%rdx, %rdi
	call	mergeSortStringhe
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-24(%rbp), %rax
	leaq	(%rdx,%rax), %rdi
	movl	-4(%rbp), %edx
	movl	-8(%rbp), %esi
	movq	-24(%rbp), %rax
	movl	%edx, %ecx
	movq	%rdi, %rdx
	movq	%rax, %rdi
	call	mergeStringhe
	jmp	.L29
.L32:
	nop
.L29:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE12:
	.size	mergeSortStringhe, .-mergeSortStringhe
	.globl	mergeCoppie
	.type	mergeCoppie, @function
mergeCoppie:
.LFB13:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%rdi, -40(%rbp)
	movl	%esi, -44(%rbp)
	movq	%rdx, -56(%rbp)
	movl	%ecx, -48(%rbp)
	movl	-44(%rbp), %edx
	movl	-48(%rbp), %eax
	addl	%edx, %eax
	cltq
	salq	$3, %rax
	movq	%rax, %rdi
	call	malloc@PLT
	movq	%rax, -8(%rbp)
	movl	$0, -24(%rbp)
	movl	$0, -20(%rbp)
	movl	$0, -16(%rbp)
	jmp	.L34
.L40:
	movl	-24(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movl	(%rax), %edx
	movl	-20(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rcx
	movq	-56(%rbp), %rax
	addq	%rcx, %rax
	movq	(%rax), %rax
	movl	(%rax), %eax
	cmpl	%eax, %edx
	jge	.L35
	movl	-24(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movl	-16(%rbp), %edx
	movslq	%edx, %rdx
	leaq	0(,%rdx,8), %rcx
	movq	-8(%rbp), %rdx
	addq	%rcx, %rdx
	movq	(%rax), %rax
	movq	%rax, (%rdx)
	addl	$1, -24(%rbp)
	jmp	.L36
.L35:
	movl	-24(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movl	(%rax), %edx
	movl	-20(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rcx
	movq	-56(%rbp), %rax
	addq	%rcx, %rax
	movq	(%rax), %rax
	movl	(%rax), %eax
	cmpl	%eax, %edx
	jle	.L37
	movl	-20(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-56(%rbp), %rax
	addq	%rdx, %rax
	movl	-16(%rbp), %edx
	movslq	%edx, %rdx
	leaq	0(,%rdx,8), %rcx
	movq	-8(%rbp), %rdx
	addq	%rcx, %rdx
	movq	(%rax), %rax
	movq	%rax, (%rdx)
	addl	$1, -20(%rbp)
	jmp	.L36
.L37:
	movl	-24(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movl	4(%rax), %edx
	movl	-20(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rcx
	movq	-56(%rbp), %rax
	addq	%rcx, %rax
	movq	(%rax), %rax
	movl	4(%rax), %eax
	cmpl	%eax, %edx
	jge	.L38
	movl	-24(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movl	-16(%rbp), %edx
	movslq	%edx, %rdx
	leaq	0(,%rdx,8), %rcx
	movq	-8(%rbp), %rdx
	addq	%rcx, %rdx
	movq	(%rax), %rax
	movq	%rax, (%rdx)
	addl	$1, -24(%rbp)
	jmp	.L36
.L38:
	movl	-24(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movl	4(%rax), %edx
	movl	-20(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rcx
	movq	-56(%rbp), %rax
	addq	%rcx, %rax
	movq	(%rax), %rax
	movl	4(%rax), %eax
	cmpl	%eax, %edx
	jle	.L36
	movl	-20(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-56(%rbp), %rax
	addq	%rdx, %rax
	movl	-16(%rbp), %edx
	movslq	%edx, %rdx
	leaq	0(,%rdx,8), %rcx
	movq	-8(%rbp), %rdx
	addq	%rcx, %rdx
	movq	(%rax), %rax
	movq	%rax, (%rdx)
	addl	$1, -20(%rbp)
.L36:
	addl	$1, -16(%rbp)
.L34:
	movl	-24(%rbp), %eax
	cmpl	-44(%rbp), %eax
	je	.L41
	movl	-20(%rbp), %eax
	cmpl	-48(%rbp), %eax
	jne	.L40
	jmp	.L41
.L44:
	movl	-24(%rbp), %eax
	cmpl	-44(%rbp), %eax
	je	.L42
	movl	-24(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movl	-16(%rbp), %edx
	movslq	%edx, %rdx
	leaq	0(,%rdx,8), %rcx
	movq	-8(%rbp), %rdx
	addq	%rcx, %rdx
	movq	(%rax), %rax
	movq	%rax, (%rdx)
	addl	$1, -24(%rbp)
	jmp	.L43
.L42:
	movl	-20(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-56(%rbp), %rax
	addq	%rdx, %rax
	movl	-16(%rbp), %edx
	movslq	%edx, %rdx
	leaq	0(,%rdx,8), %rcx
	movq	-8(%rbp), %rdx
	addq	%rcx, %rdx
	movq	(%rax), %rax
	movq	%rax, (%rdx)
	addl	$1, -20(%rbp)
.L43:
	addl	$1, -16(%rbp)
.L41:
	movl	-44(%rbp), %edx
	movl	-48(%rbp), %eax
	addl	%edx, %eax
	cmpl	%eax, -16(%rbp)
	jl	.L44
	movl	$0, -12(%rbp)
	jmp	.L45
.L46:
	movl	-12(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-8(%rbp), %rax
	addq	%rdx, %rax
	movl	-12(%rbp), %edx
	movslq	%edx, %rdx
	leaq	0(,%rdx,8), %rcx
	movq	-40(%rbp), %rdx
	addq	%rcx, %rdx
	movq	(%rax), %rax
	movq	%rax, (%rdx)
	addl	$1, -12(%rbp)
.L45:
	movl	-12(%rbp), %eax
	cmpl	-16(%rbp), %eax
	jl	.L46
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE13:
	.size	mergeCoppie, .-mergeCoppie
	.globl	mergeSortCoppie
	.type	mergeSortCoppie, @function
mergeSortCoppie:
.LFB14:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	cmpl	$1, -28(%rbp)
	je	.L50
	movl	-28(%rbp), %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	movl	%eax, -8(%rbp)
	movl	-28(%rbp), %eax
	subl	-8(%rbp), %eax
	movl	%eax, -4(%rbp)
	movl	-8(%rbp), %edx
	movq	-24(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	mergeSortCoppie
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-24(%rbp), %rax
	addq	%rax, %rdx
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	movq	%rdx, %rdi
	call	mergeSortCoppie
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-24(%rbp), %rax
	leaq	(%rdx,%rax), %rdi
	movl	-4(%rbp), %edx
	movl	-8(%rbp), %esi
	movq	-24(%rbp), %rax
	movl	%edx, %ecx
	movq	%rdi, %rdx
	movq	%rax, %rdi
	call	mergeCoppie
	jmp	.L47
.L50:
	nop
.L47:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE14:
	.size	mergeSortCoppie, .-mergeSortCoppie
	.globl	concat
	.type	concat, @function
concat:
.LFB15:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r12
	pushq	%rbx
	subq	$32, %rsp
	.cfi_offset 12, -24
	.cfi_offset 3, -32
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movq	%rax, %rbx
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	addq	%rbx, %rax
	addq	$1, %rax
	movq	%rax, %rdi
	call	malloc@PLT
	movq	%rax, -24(%rbp)
	movl	$0, -32(%rbp)
	jmp	.L52
.L53:
	movl	-32(%rbp), %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movl	-32(%rbp), %edx
	movslq	%edx, %rcx
	movq	-24(%rbp), %rdx
	addq	%rcx, %rdx
	movzbl	(%rax), %eax
	movb	%al, (%rdx)
	addl	$1, -32(%rbp)
.L52:
	movl	-32(%rbp), %eax
	movslq	%eax, %rbx
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	cmpq	%rax, %rbx
	jb	.L53
	movl	$0, -28(%rbp)
	jmp	.L54
.L55:
	movl	-28(%rbp), %eax
	movslq	%eax, %rdx
	movq	-48(%rbp), %rax
	leaq	(%rdx,%rax), %rbx
	movl	-28(%rbp), %eax
	movslq	%eax, %r12
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	leaq	(%r12,%rax), %rdx
	movq	-24(%rbp), %rax
	addq	%rax, %rdx
	movzbl	(%rbx), %eax
	movb	%al, (%rdx)
	addl	$1, -28(%rbp)
.L54:
	movl	-28(%rbp), %eax
	movslq	%eax, %rbx
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	cmpq	%rax, %rbx
	jb	.L55
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movq	%rax, %rbx
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	leaq	(%rbx,%rax), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movb	$0, (%rax)
	movq	-24(%rbp), %rax
	addq	$32, %rsp
	popq	%rbx
	popq	%r12
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE15:
	.size	concat, .-concat
	.section	.rodata
	.align 8
.LC1:
	.string	"il programma deve essere parole nomfile"
.LC2:
	.string	"r"
.LC3:
	.string	".ordinato"
.LC4:
	.string	"w"
.LC5:
	.string	".prima"
.LC6:
	.string	".dopo"
.LC7:
	.string	"malloc fallita"
.LC8:
	.string	"%ms"
.LC9:
	.string	"fscanf fallita"
.LC10:
	.string	"%s \n"
.LC11:
	.string	"%d %d \n"
.LC12:
	.string	"%d %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB16:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$136, %rsp
	.cfi_offset 3, -24
	movl	%edi, -132(%rbp)
	movq	%rsi, -144(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	cmpl	$2, -132(%rbp)
	je	.L58
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	call	termina
.L58:
	movq	-144(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	leaq	.LC2(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	fopen@PLT
	movq	%rax, -80(%rbp)
	movq	-144(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	leaq	.LC3(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	concat
	movq	%rax, -72(%rbp)
	leaq	.LC4(%rip), %rdx
	movq	-72(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	fopen@PLT
	movq	%rax, -64(%rbp)
	movq	-72(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
	movq	-144(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	leaq	.LC5(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	concat
	movq	%rax, -72(%rbp)
	leaq	.LC4(%rip), %rdx
	movq	-72(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	fopen@PLT
	movq	%rax, -56(%rbp)
	movq	-72(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
	movq	-144(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	leaq	.LC6(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	concat
	movq	%rax, -72(%rbp)
	leaq	.LC4(%rip), %rdx
	movq	-72(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	fopen@PLT
	movq	%rax, -48(%rbp)
	movq	-72(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
	movl	$0, -120(%rbp)
	movl	$10, -116(%rbp)
	movl	-116(%rbp), %eax
	cltq
	salq	$3, %rax
	movq	%rax, %rdi
	call	malloc@PLT
	movq	%rax, -88(%rbp)
	cmpq	$0, -88(%rbp)
	jne	.L59
	leaq	.LC7(%rip), %rax
	movq	%rax, %rdi
	call	termina
.L59:
	movl	$0, -100(%rbp)
.L64:
	movl	-120(%rbp), %eax
	cmpl	-116(%rbp), %eax
	jne	.L60
	sall	-116(%rbp)
	movl	-116(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, -88(%rbp)
.L60:
	leaq	-96(%rbp), %rdx
	leaq	.LC8(%rip), %rcx
	movq	-80(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc23_fscanf@PLT
	movl	%eax, -100(%rbp)
	cmpl	$-1, -100(%rbp)
	jne	.L61
	movl	-120(%rbp), %edx
	movq	-88(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	mergeSortStringhe
	movl	$0, -112(%rbp)
	jmp	.L62
.L61:
	cmpl	$1, -100(%rbp)
	je	.L63
	leaq	.LC9(%rip), %rax
	movq	%rax, %rdi
	call	termina
.L63:
	movl	-120(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-88(%rbp), %rax
	addq	%rax, %rdx
	movq	-96(%rbp), %rax
	movq	%rax, (%rdx)
	addl	$1, -120(%rbp)
	jmp	.L64
.L65:
	movl	-112(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-88(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rdx
	leaq	.LC10(%rip), %rcx
	movq	-64(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	addl	$1, -112(%rbp)
.L62:
	movl	-112(%rbp), %eax
	cmpl	-120(%rbp), %eax
	jl	.L65
	movl	-120(%rbp), %eax
	cltq
	salq	$3, %rax
	movq	%rax, %rdi
	call	malloc@PLT
	movq	%rax, -40(%rbp)
	cmpq	$0, -40(%rbp)
	jne	.L66
	leaq	.LC7(%rip), %rax
	movq	%rax, %rdi
	call	termina
.L66:
	movl	$0, -108(%rbp)
	jmp	.L67
.L68:
	movl	-108(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-88(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, %ebx
	movl	-108(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-88(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	numOfHastag
	movl	%ebx, %esi
	movl	%eax, %edi
	call	create_coppia
	movq	%rax, -32(%rbp)
	movl	-108(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-40(%rbp), %rax
	addq	%rax, %rdx
	movq	-32(%rbp), %rax
	movq	%rax, (%rdx)
	movq	-32(%rbp), %rax
	movl	4(%rax), %ecx
	movq	-32(%rbp), %rax
	movl	(%rax), %edx
	leaq	.LC11(%rip), %rsi
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	addl	$1, -108(%rbp)
.L67:
	movl	-108(%rbp), %eax
	cmpl	-120(%rbp), %eax
	jl	.L68
	movl	-120(%rbp), %edx
	movq	-40(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	mergeSortCoppie
	movl	$0, -104(%rbp)
	jmp	.L69
.L70:
	movl	-104(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movl	4(%rax), %ecx
	movl	-104(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movl	(%rax), %edx
	leaq	.LC12(%rip), %rsi
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	addl	$1, -104(%rbp)
.L69:
	movl	-104(%rbp), %eax
	cmpl	-120(%rbp), %eax
	jl	.L70
	movq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	fclose@PLT
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	fclose@PLT
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	fclose@PLT
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	fclose@PLT
	movl	-120(%rbp), %edx
	movq	-40(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	destroyarrcoppia
	movl	-120(%rbp), %edx
	movq	-88(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	destroyarrstring
	movl	$0, %eax
	movq	-24(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L72
	call	__stack_chk_fail@PLT
.L72:
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE16:
	.size	main, .-main
	.ident	"GCC: (GNU) 15.2.1 20250813"
	.section	.note.GNU-stack,"",@progbits
