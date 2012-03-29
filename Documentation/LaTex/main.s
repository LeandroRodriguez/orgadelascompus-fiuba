	.file	1 "tp.c"
	.section .mdebug.abi32
	.previous
	.abicalls
	.text
	.align	2
	.globl	SelectionSort
	.ent	SelectionSort
SelectionSort:
	.frame	$fp,32,$ra		# vars= 16, regs= 2/0, args= 0, extra= 8
	.mask	0x50000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.cpload	$t9
	.set	reorder
	subu	$sp,$sp,32
	.cprestore 0
	sw	$fp,28($sp)
	sw	$gp,24($sp)
	move	$fp,$sp
	sw	$a0,32($fp)
	sw	$a1,36($fp)
	lw	$v0,36($fp)
	slt	$v0,$v0,2
	bne	$v0,$zero,$L17
	sw	$zero,8($fp)
	sw	$zero,12($fp)
$L19:
	lw	$v0,36($fp)
	addu	$v1,$v0,-1
	lw	$v0,12($fp)
	slt	$v0,$v0,$v1
	bne	$v0,$zero,$L22
	b	$L17
$L22:
	lw	$v0,12($fp)
	sw	$v0,8($fp)
	lw	$v0,12($fp)
	addu	$v0,$v0,1
	sw	$v0,16($fp)
$L23:
	lw	$v0,16($fp)
	lw	$v1,36($fp)
	slt	$v0,$v0,$v1
	bne	$v0,$zero,$L26
	b	$L24
$L26:
	lw	$v1,32($fp)
	lw	$v0,8($fp)
	addu	$a0,$v1,$v0
	lw	$v1,32($fp)
	lw	$v0,16($fp)
	addu	$v0,$v1,$v0
	lbu	$v1,0($a0)
	lbu	$v0,0($v0)
	sltu	$v0,$v0,$v1
	beq	$v0,$zero,$L25
	lw	$v0,16($fp)
	sw	$v0,8($fp)
$L25:
	lw	$v0,16($fp)
	addu	$v0,$v0,1
	sw	$v0,16($fp)
	b	$L23
$L24:
	lw	$v1,32($fp)
	lw	$v0,8($fp)
	addu	$v0,$v1,$v0
	lbu	$v0,0($v0)
	sb	$v0,20($fp)
	lw	$v1,32($fp)
	lw	$v0,8($fp)
	addu	$a0,$v1,$v0
	lw	$v1,32($fp)
	lw	$v0,12($fp)
	addu	$v0,$v1,$v0
	lbu	$v0,0($v0)
	sb	$v0,0($a0)
	lw	$v1,32($fp)
	lw	$v0,12($fp)
	addu	$v1,$v1,$v0
	lbu	$v0,20($fp)
	sb	$v0,0($v1)
	lw	$v0,12($fp)
	addu	$v0,$v0,1
	sw	$v0,12($fp)
	b	$L19
$L17:
	move	$sp,$fp
	lw	$fp,28($sp)
	addu	$sp,$sp,32
	j	$ra
	.end	SelectionSort
	.size	SelectionSort, .-SelectionSort
	.align	2
	.globl	Merge
	.ent	Merge
Merge:
	.frame	$fp,32,$ra		# vars= 16, regs= 2/0, args= 0, extra= 8
	.mask	0x50000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.cpload	$t9
	.set	reorder
	subu	$sp,$sp,32
	.cprestore 0
	sw	$fp,28($sp)
	sw	$gp,24($sp)
	move	$fp,$sp
	sw	$a0,32($fp)
	sw	$a1,36($fp)
	sw	$a2,40($fp)
	sw	$a3,44($fp)
	sw	$zero,8($fp)
	sw	$zero,12($fp)
	sw	$zero,16($fp)
$L29:
	lw	$v0,8($fp)
	lw	$v1,36($fp)
	slt	$v0,$v0,$v1
	beq	$v0,$zero,$L30
	lw	$v0,12($fp)
	lw	$v1,44($fp)
	slt	$v0,$v0,$v1
	bne	$v0,$zero,$L31
	b	$L30
$L31:
	lw	$v1,32($fp)
	lw	$v0,8($fp)
	addu	$a0,$v1,$v0
	lw	$v1,40($fp)
	lw	$v0,12($fp)
	addu	$v0,$v1,$v0
	lbu	$v1,0($a0)
	lbu	$v0,0($v0)
	sltu	$v0,$v1,$v0
	beq	$v0,$zero,$L33
	lw	$v1,48($fp)
	lw	$v0,16($fp)
	addu	$a0,$v1,$v0
	lw	$v1,32($fp)
	lw	$v0,8($fp)
	addu	$v0,$v1,$v0
	lbu	$v0,0($v0)
	sb	$v0,0($a0)
	lw	$v0,8($fp)
	addu	$v0,$v0,1
	sw	$v0,8($fp)
	b	$L34
$L33:
	lw	$v1,48($fp)
	lw	$v0,16($fp)
	addu	$a0,$v1,$v0
	lw	$v1,40($fp)
	lw	$v0,12($fp)
	addu	$v0,$v1,$v0
	lbu	$v0,0($v0)
	sb	$v0,0($a0)
	lw	$v0,12($fp)
	addu	$v0,$v0,1
	sw	$v0,12($fp)
$L34:
	lw	$v0,16($fp)
	addu	$v0,$v0,1
	sw	$v0,16($fp)
	b	$L29
$L30:
	.set	noreorder
	nop
	.set	reorder
$L35:
	lw	$v0,8($fp)
	lw	$v1,36($fp)
	slt	$v0,$v0,$v1
	bne	$v0,$zero,$L37
	b	$L36
$L37:
	lw	$v1,48($fp)
	lw	$v0,16($fp)
	addu	$a0,$v1,$v0
	lw	$v1,32($fp)
	lw	$v0,8($fp)
	addu	$v0,$v1,$v0
	lbu	$v0,0($v0)
	sb	$v0,0($a0)
	lw	$v0,8($fp)
	addu	$v0,$v0,1
	sw	$v0,8($fp)
	lw	$v0,16($fp)
	addu	$v0,$v0,1
	sw	$v0,16($fp)
	b	$L35
$L36:
	.set	noreorder
	nop
	.set	reorder
$L38:
	lw	$v0,12($fp)
	lw	$v1,44($fp)
	slt	$v0,$v0,$v1
	bne	$v0,$zero,$L40
	b	$L28
$L40:
	lw	$v1,48($fp)
	lw	$v0,16($fp)
	addu	$a0,$v1,$v0
	lw	$v1,40($fp)
	lw	$v0,12($fp)
	addu	$v0,$v1,$v0
	lbu	$v0,0($v0)
	sb	$v0,0($a0)
	lw	$v0,12($fp)
	addu	$v0,$v0,1
	sw	$v0,12($fp)
	lw	$v0,16($fp)
	addu	$v0,$v0,1
	sw	$v0,16($fp)
	b	$L38
$L28:
	move	$sp,$fp
	lw	$fp,28($sp)
	addu	$sp,$sp,32
	j	$ra
	.end	Merge
	.size	Merge, .-Merge
	.align	2
	.globl	MergeSort
	.ent	MergeSort
MergeSort:
	.frame	$fp,72,$ra		# vars= 24, regs= 3/0, args= 24, extra= 8
	.mask	0xd0000000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.cpload	$t9
	.set	reorder
	subu	$sp,$sp,72
	.cprestore 24
	sw	$ra,64($sp)
	sw	$fp,60($sp)
	sw	$gp,56($sp)
	move	$fp,$sp
	sw	$a0,72($fp)
	sw	$a1,76($fp)
	lw	$v0,76($fp)
	slt	$v0,$v0,2
	bne	$v0,$zero,$L41
	lw	$v0,76($fp)
	andi	$v0,$v0,0x1
	bne	$v0,$zero,$L43
	lw	$v1,76($fp)
	sra	$v0,$v1,31
	srl	$v0,$v0,31
	addu	$v0,$v1,$v0
	sra	$v0,$v0,1
	sw	$v0,44($fp)
	sw	$v0,40($fp)
	b	$L44
$L43:
	lw	$v1,76($fp)
	sra	$v0,$v1,31
	srl	$v0,$v0,31
	addu	$v0,$v1,$v0
	sra	$v0,$v0,1
	sw	$v0,40($fp)
	lw	$v0,40($fp)
	addu	$v0,$v0,1
	sw	$v0,44($fp)
$L44:
	lw	$a0,40($fp)
	la	$t9,malloc
	jal	$ra,$t9
	sw	$v0,32($fp)
	lw	$a0,44($fp)
	la	$t9,malloc
	jal	$ra,$t9
	sw	$v0,36($fp)
	sw	$zero,48($fp)
$L45:
	lw	$v0,48($fp)
	lw	$v1,40($fp)
	slt	$v0,$v0,$v1
	bne	$v0,$zero,$L48
	b	$L46
$L48:
	lw	$v1,32($fp)
	lw	$v0,48($fp)
	addu	$a0,$v1,$v0
	lw	$v1,72($fp)
	lw	$v0,48($fp)
	addu	$v0,$v1,$v0
	lbu	$v0,0($v0)
	sb	$v0,0($a0)
	lw	$v0,48($fp)
	addu	$v0,$v0,1
	sw	$v0,48($fp)
	b	$L45
$L46:
	sw	$zero,52($fp)
$L49:
	lw	$v0,52($fp)
	lw	$v1,44($fp)
	slt	$v0,$v0,$v1
	bne	$v0,$zero,$L52
	b	$L50
$L52:
	lw	$v1,36($fp)
	lw	$v0,52($fp)
	addu	$a0,$v1,$v0
	lw	$v1,72($fp)
	lw	$v0,48($fp)
	addu	$v0,$v1,$v0
	lbu	$v0,0($v0)
	sb	$v0,0($a0)
	lw	$v0,48($fp)
	addu	$v0,$v0,1
	sw	$v0,48($fp)
	lw	$v0,52($fp)
	addu	$v0,$v0,1
	sw	$v0,52($fp)
	b	$L49
$L50:
	lw	$a0,32($fp)
	lw	$a1,40($fp)
	la	$t9,MergeSort
	jal	$ra,$t9
	lw	$a0,36($fp)
	lw	$a1,44($fp)
	la	$t9,MergeSort
	jal	$ra,$t9
	lw	$v0,72($fp)
	sw	$v0,16($sp)
	lw	$a0,32($fp)
	lw	$a1,40($fp)
	lw	$a2,36($fp)
	lw	$a3,44($fp)
	la	$t9,Merge
	jal	$ra,$t9
	lw	$a0,32($fp)
	la	$t9,free
	jal	$ra,$t9
	lw	$a0,36($fp)
	la	$t9,free
	jal	$ra,$t9
$L41:
	move	$sp,$fp
	lw	$ra,64($sp)
	lw	$fp,60($sp)
	addu	$sp,$sp,72
	j	$ra
	.end	MergeSort
	.size	MergeSort, .-MergeSort
	.rdata
	.align	2
$LC0:
	.ascii	"%s\000"
	.align	2
$LC1:
	.ascii	"-h :  ayuda\n\000"
	.align	2
$LC2:
	.ascii	"-v :  version\n\000"
	.align	2
$LC3:
	.ascii	"-m :  merge sort\n\000"
	.align	2
$LC4:
	.ascii	"-s : selection sort\n\000"
	.align	2
$LC5:
	.ascii	"Si se ejecuta el programa sin especificar ninguna cadena"
	.ascii	"\000"
	.align	2
$LC6:
	.ascii	"se puede ingresar luego, usando el teclado.\n\000"
	.text
	.align	2
	.globl	Menu
	.ent	Menu
Menu:
	.frame	$fp,40,$ra		# vars= 0, regs= 3/0, args= 16, extra= 8
	.mask	0xd0000000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.cpload	$t9
	.set	reorder
	subu	$sp,$sp,40
	.cprestore 16
	sw	$ra,32($sp)
	sw	$fp,28($sp)
	sw	$gp,24($sp)
	move	$fp,$sp
	la	$a0,$LC0
	la	$a1,$LC1
	la	$t9,printf
	jal	$ra,$t9
	la	$a0,$LC0
	la	$a1,$LC2
	la	$t9,printf
	jal	$ra,$t9
	la	$a0,$LC0
	la	$a1,$LC3
	la	$t9,printf
	jal	$ra,$t9
	la	$a0,$LC0
	la	$a1,$LC4
	la	$t9,printf
	jal	$ra,$t9
	la	$a0,$LC0
	la	$a1,$LC5
	la	$t9,printf
	jal	$ra,$t9
	la	$a0,$LC0
	la	$a1,$LC6
	la	$t9,printf
	jal	$ra,$t9
	move	$sp,$fp
	lw	$ra,32($sp)
	lw	$fp,28($sp)
	addu	$sp,$sp,40
	j	$ra
	.end	Menu
	.size	Menu, .-Menu
	.rdata
	.align	2
$LC7:
	.ascii	"%c\000"
	.align	2
$LC8:
	.ascii	"\n\000"
	.text
	.align	2
	.globl	ExportarCadena
	.ent	ExportarCadena
ExportarCadena:
	.frame	$fp,48,$ra		# vars= 8, regs= 3/0, args= 16, extra= 8
	.mask	0xd0000000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.cpload	$t9
	.set	reorder
	subu	$sp,$sp,48
	.cprestore 16
	sw	$ra,40($sp)
	sw	$fp,36($sp)
	sw	$gp,32($sp)
	move	$fp,$sp
	sw	$a0,48($fp)
	sw	$a1,52($fp)
	sw	$zero,24($fp)
	sw	$zero,24($fp)
$L55:
	lw	$v0,24($fp)
	lw	$v1,52($fp)
	sltu	$v0,$v0,$v1
	bne	$v0,$zero,$L58
	b	$L56
$L58:
	lw	$v1,48($fp)
	lw	$v0,24($fp)
	addu	$v0,$v1,$v0
	lbu	$v0,0($v0)
	la	$a0,$LC7
	move	$a1,$v0
	la	$t9,printf
	jal	$ra,$t9
	lw	$v0,24($fp)
	addu	$v0,$v0,1
	sw	$v0,24($fp)
	b	$L55
$L56:
	la	$a0,$LC8
	la	$t9,printf
	jal	$ra,$t9
	move	$sp,$fp
	lw	$ra,40($sp)
	lw	$fp,36($sp)
	addu	$sp,$sp,48
	j	$ra
	.end	ExportarCadena
	.size	ExportarCadena, .-ExportarCadena
	.align	2
	.globl	SubLeer
	.ent	SubLeer
SubLeer:
	.frame	$fp,72,$ra		# vars= 32, regs= 3/0, args= 16, extra= 8
	.mask	0xd0000000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.cpload	$t9
	.set	reorder
	subu	$sp,$sp,72
	.cprestore 16
	sw	$ra,64($sp)
	sw	$fp,60($sp)
	sw	$gp,56($sp)
	move	$fp,$sp
	sw	$a0,72($fp)
	sw	$a1,76($fp)
	li	$v0,1			# 0x1
	sw	$v0,24($fp)
	sw	$zero,28($fp)
	sw	$zero,32($fp)
	li	$v0,100			# 0x64
	sw	$v0,36($fp)
	lw	$v1,24($fp)
	move	$v0,$v1
	sll	$v0,$v0,1
	addu	$v0,$v0,$v1
	sll	$v0,$v0,3
	addu	$v0,$v0,$v1
	sll	$v0,$v0,2
	move	$a0,$v0
	la	$t9,malloc
	jal	$ra,$t9
	sw	$v0,40($fp)
	lw	$v1,24($fp)
	move	$v0,$v1
	sll	$v0,$v0,1
	addu	$v0,$v0,$v1
	sll	$v0,$v0,3
	addu	$v0,$v0,$v1
	sll	$v0,$v0,2
	move	$a0,$v0
	la	$t9,malloc
	jal	$ra,$t9
	sw	$v0,44($fp)
	sw	$zero,48($fp)
$L60:
	lw	$a0,40($fp)
	lw	$a1,24($fp)
	li	$a2,100			# 0x64
	lw	$a3,72($fp)
	la	$t9,fread
	jal	$ra,$t9
	sw	$v0,28($fp)
	lw	$v0,28($fp)
	bne	$v0,$zero,$L62
	b	$L61
$L62:
	lw	$v1,32($fp)
	lw	$v0,28($fp)
	addu	$v1,$v1,$v0
	lw	$v0,36($fp)
	sltu	$v0,$v1,$v0
	bne	$v0,$zero,$L63
	lw	$v1,36($fp)
	move	$v0,$v1
	sll	$v0,$v0,1
	addu	$v0,$v0,$v1
	sw	$v0,36($fp)
	lw	$v1,24($fp)
	lw	$v0,36($fp)
	mult	$v1,$v0
	mflo	$v0
	lw	$a0,44($fp)
	move	$a1,$v0
	la	$t9,realloc
	jal	$ra,$t9
	sw	$v0,48($fp)
	lw	$v0,48($fp)
	bne	$v0,$zero,$L64
	b	$L61
$L64:
	lw	$v0,48($fp)
	sw	$v0,44($fp)
$L63:
	lw	$v1,44($fp)
	lw	$v0,32($fp)
	addu	$v0,$v1,$v0
	move	$a0,$v0
	lw	$a1,40($fp)
	lw	$a2,28($fp)
	la	$t9,memcpy
	jal	$ra,$t9
	lw	$v1,32($fp)
	lw	$v0,28($fp)
	addu	$v0,$v1,$v0
	sw	$v0,32($fp)
	b	$L60
$L61:
	lw	$a0,40($fp)
	la	$t9,free
	jal	$ra,$t9
	lw	$v1,24($fp)
	lw	$v0,32($fp)
	mult	$v1,$v0
	mflo	$v0
	lw	$a0,44($fp)
	move	$a1,$v0
	la	$t9,realloc
	jal	$ra,$t9
	sw	$v0,48($fp)
	lw	$v0,48($fp)
	bne	$v0,$zero,$L65
	lw	$v0,48($fp)
	sw	$v0,44($fp)
$L65:
	lw	$v1,76($fp)
	lw	$v0,32($fp)
	sw	$v0,0($v1)
	lw	$a0,72($fp)
	la	$t9,fclose
	jal	$ra,$t9
	lw	$v0,44($fp)
	move	$sp,$fp
	lw	$ra,64($sp)
	lw	$fp,60($sp)
	addu	$sp,$sp,72
	j	$ra
	.end	SubLeer
	.size	SubLeer, .-SubLeer
	.rdata
	.align	2
$LC9:
	.ascii	"rb\000"
	.text
	.align	2
	.globl	LeerArchivoDeCaracteres
	.ent	LeerArchivoDeCaracteres
LeerArchivoDeCaracteres:
	.frame	$fp,48,$ra		# vars= 8, regs= 3/0, args= 16, extra= 8
	.mask	0xd0000000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.cpload	$t9
	.set	reorder
	subu	$sp,$sp,48
	.cprestore 16
	sw	$ra,40($sp)
	sw	$fp,36($sp)
	sw	$gp,32($sp)
	move	$fp,$sp
	sw	$a0,48($fp)
	sw	$a1,52($fp)
	lw	$v0,48($fp)
	bne	$v0,$zero,$L67
	sw	$zero,28($fp)
	b	$L66
$L67:
	lw	$a0,48($fp)
	la	$a1,$LC9
	la	$t9,fopen
	jal	$ra,$t9
	sw	$v0,24($fp)
	lw	$v0,24($fp)
	bne	$v0,$zero,$L68
	sw	$zero,28($fp)
	b	$L66
$L68:
	lw	$a0,24($fp)
	lw	$a1,52($fp)
	la	$t9,SubLeer
	jal	$ra,$t9
	sw	$v0,28($fp)
$L66:
	lw	$v0,28($fp)
	move	$sp,$fp
	lw	$ra,40($sp)
	lw	$fp,36($sp)
	addu	$sp,$sp,48
	j	$ra
	.end	LeerArchivoDeCaracteres
	.size	LeerArchivoDeCaracteres, .-LeerArchivoDeCaracteres
	.align	2
	.globl	SumarCadenas
	.ent	SumarCadenas
SumarCadenas:
	.frame	$fp,48,$ra		# vars= 8, regs= 3/0, args= 16, extra= 8
	.mask	0xd0000000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.cpload	$t9
	.set	reorder
	subu	$sp,$sp,48
	.cprestore 16
	sw	$ra,40($sp)
	sw	$fp,36($sp)
	sw	$gp,32($sp)
	move	$fp,$sp
	sw	$a0,48($fp)
	sw	$a1,52($fp)
	sw	$a2,56($fp)
	sw	$a3,60($fp)
	lw	$v1,52($fp)
	lw	$v0,60($fp)
	addu	$v0,$v1,$v0
	move	$a0,$v0
	la	$t9,malloc
	jal	$ra,$t9
	sw	$v0,24($fp)
	sw	$zero,28($fp)
	sw	$zero,28($fp)
$L70:
	lw	$v0,28($fp)
	lw	$v1,52($fp)
	sltu	$v0,$v0,$v1
	bne	$v0,$zero,$L73
	b	$L71
$L73:
	lw	$v1,24($fp)
	lw	$v0,28($fp)
	addu	$a0,$v1,$v0
	lw	$v1,48($fp)
	lw	$v0,28($fp)
	addu	$v0,$v1,$v0
	lbu	$v0,0($v0)
	sb	$v0,0($a0)
	lw	$v0,28($fp)
	addu	$v0,$v0,1
	sw	$v0,28($fp)
	b	$L70
$L71:
	lw	$v0,52($fp)
	sw	$v0,28($fp)
$L74:
	lw	$v1,52($fp)
	lw	$v0,60($fp)
	addu	$v1,$v1,$v0
	lw	$v0,28($fp)
	sltu	$v0,$v0,$v1
	bne	$v0,$zero,$L77
	b	$L75
$L77:
	lw	$v1,24($fp)
	lw	$v0,28($fp)
	addu	$a0,$v1,$v0
	lw	$v1,28($fp)
	lw	$v0,52($fp)
	subu	$v1,$v1,$v0
	lw	$v0,56($fp)
	addu	$v0,$v1,$v0
	lbu	$v0,0($v0)
	sb	$v0,0($a0)
	lw	$v0,28($fp)
	addu	$v0,$v0,1
	sw	$v0,28($fp)
	b	$L74
$L75:
	lw	$v0,24($fp)
	move	$sp,$fp
	lw	$ra,40($sp)
	lw	$fp,36($sp)
	addu	$sp,$sp,48
	j	$ra
	.end	SumarCadenas
	.size	SumarCadenas, .-SumarCadenas
	.rdata
	.align	2
$LC11:
	.ascii	"help\000"
	.align	2
$LC12:
	.ascii	"version\000"
	.align	2
$LC13:
	.ascii	"merge sort\000"
	.align	2
$LC14:
	.ascii	"selection sort\000"
	.data
	.align	2
$LC15:
	.word	$LC11
	.word	0
	.word	0
	.word	104
	.word	$LC12
	.word	0
	.word	0
	.word	118
	.word	$LC13
	.word	1
	.word	0
	.word	109
	.word	$LC14
	.word	1
	.word	0
	.word	115
	.globl	memcpy
	.rdata
	.align	2
$LC10:
	.ascii	"hvms\000"
	.align	2
$LC16:
	.ascii	"Opcion no valida.Tipee -h o --help y pruebe de vuelta\n\000"
	.align	2
$LC17:
	.ascii	"Programa version:1.0 Creditos:TomReaFpiechoLeanRo\n\000"
	.text
	.align	2
	.globl	main
	.ent	main
main:
	.frame	$fp,152,$ra		# vars= 104, regs= 3/0, args= 24, extra= 8
	.mask	0xd0000000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.cpload	$t9
	.set	reorder
	subu	$sp,$sp,152
	.cprestore 24
	sw	$ra,144($sp)
	sw	$fp,140($sp)
	sw	$gp,136($sp)
	move	$fp,$sp
	sw	$a0,152($fp)
	sw	$a1,156($fp)
	sw	$zero,32($fp)
	sw	$zero,36($fp)
	la	$v0,$LC10
	sw	$v0,40($fp)
	addu	$v0,$fp,48
	la	$v1,$LC15
	move	$a0,$v0
	move	$a1,$v1
	li	$a2,64			# 0x40
	la	$t9,memcpy
	jal	$ra,$t9
$L79:
	addu	$v0,$fp,48
	sw	$zero,16($sp)
	lw	$a0,152($fp)
	lw	$a1,156($fp)
	lw	$a2,40($fp)
	move	$a3,$v0
	la	$t9,getopt_long
	jal	$ra,$t9
	sw	$v0,112($fp)
	lw	$v1,112($fp)
	li	$v0,-1			# 0xffffffffffffffff
	bne	$v1,$v0,$L82
	lw	$v0,32($fp)
	beq	$v0,$zero,$L80
	lw	$v0,36($fp)
	beq	$v0,$zero,$L80
	sw	$zero,32($fp)
	sw	$zero,36($fp)
	la	$a0,$LC0
	la	$a1,$LC16
	la	$t9,printf
	jal	$ra,$t9
	move	$a0,$zero
	la	$t9,exit
	jal	$ra,$t9
$L82:
	lw	$v0,112($fp)
	sw	$v0,132($fp)
	li	$v0,109			# 0x6d
	lw	$v1,132($fp)
	beq	$v1,$v0,$L88
	lw	$v1,132($fp)
	slt	$v0,$v1,110
	beq	$v0,$zero,$L93
	li	$v0,63			# 0x3f
	lw	$v1,132($fp)
	beq	$v1,$v0,$L90
	li	$v0,104			# 0x68
	lw	$v1,132($fp)
	beq	$v1,$v0,$L86
	b	$L79
$L93:
	li	$v0,115			# 0x73
	lw	$v1,132($fp)
	beq	$v1,$v0,$L89
	li	$v0,118			# 0x76
	lw	$v1,132($fp)
	beq	$v1,$v0,$L87
	b	$L79
$L86:
	la	$t9,Menu
	jal	$ra,$t9
	move	$a0,$zero
	la	$t9,exit
	jal	$ra,$t9
$L87:
	la	$a0,$LC0
	la	$a1,$LC17
	la	$t9,printf
	jal	$ra,$t9
	move	$a0,$zero
	la	$t9,exit
	jal	$ra,$t9
$L88:
	li	$v0,1			# 0x1
	sw	$v0,32($fp)
	b	$L79
$L89:
	li	$v0,1			# 0x1
	sw	$v0,36($fp)
	b	$L79
$L90:
	la	$a0,$LC0
	la	$a1,$LC16
	la	$t9,printf
	jal	$ra,$t9
	move	$a0,$zero
	la	$t9,exit
	jal	$ra,$t9
$L80:
	li	$a0,1			# 0x1
	la	$t9,malloc
	jal	$ra,$t9
	sw	$v0,112($fp)
	sw	$zero,116($fp)
	sw	$zero,120($fp)
	lw	$v1,optind
	lw	$v0,152($fp)
	slt	$v0,$v1,$v0
	beq	$v0,$zero,$L94
$L95:
	lw	$v0,optind
	lw	$v1,152($fp)
	slt	$v0,$v0,$v1
	bne	$v0,$zero,$L97
	b	$L100
$L97:
	sw	$zero,124($fp)
	lw	$v0,optind
	sll	$v1,$v0,2
	lw	$v0,156($fp)
	addu	$v0,$v1,$v0
	addu	$v1,$fp,124
	lw	$a0,0($v0)
	move	$a1,$v1
	la	$t9,LeerArchivoDeCaracteres
	jal	$ra,$t9
	sw	$v0,128($fp)
	lw	$v0,optind
	addu	$v0,$v0,1
	sw	$v0,optind
	lw	$v0,128($fp)
	beq	$v0,$zero,$L95
	lw	$a0,116($fp)
	lw	$a1,120($fp)
	lw	$a2,128($fp)
	lw	$a3,124($fp)
	la	$t9,SumarCadenas
	jal	$ra,$t9
	sw	$v0,112($fp)
	lw	$v0,112($fp)
	beq	$v0,$zero,$L95
	lw	$v0,112($fp)
	sw	$v0,116($fp)
	lw	$v1,120($fp)
	lw	$v0,124($fp)
	addu	$v0,$v1,$v0
	sw	$v0,120($fp)
	lw	$a0,128($fp)
	la	$t9,free
	jal	$ra,$t9
	sw	$zero,112($fp)
	b	$L95
$L94:
	addu	$v0,$fp,120
	la	$a0,__sF
	move	$a1,$v0
	la	$t9,SubLeer
	jal	$ra,$t9
	sw	$v0,116($fp)
$L100:
	lw	$v0,120($fp)
	beq	$v0,$zero,$L101
	lw	$v0,32($fp)
	beq	$v0,$zero,$L102
	lw	$a0,116($fp)
	lw	$a1,120($fp)
	la	$t9,MergeSort
	jal	$ra,$t9
$L102:
	lw	$v0,36($fp)
	beq	$v0,$zero,$L103
	lw	$a0,116($fp)
	lw	$a1,120($fp)
	la	$t9,SelectionSort
	jal	$ra,$t9
$L103:
	lw	$v0,32($fp)
	bne	$v0,$zero,$L104
	lw	$v0,36($fp)
	bne	$v0,$zero,$L104
	lw	$a0,116($fp)
	lw	$a1,120($fp)
	la	$t9,SelectionSort
	jal	$ra,$t9
$L104:
	lw	$a0,116($fp)
	lw	$a1,120($fp)
	la	$t9,ExportarCadena
	jal	$ra,$t9
	lw	$a0,116($fp)
	la	$t9,free
	jal	$ra,$t9
	sw	$zero,116($fp)
$L101:
	move	$v0,$zero
	move	$sp,$fp
	lw	$ra,144($sp)
	lw	$fp,140($sp)
	addu	$sp,$sp,152
	j	$ra
	.end	main
	.size	main, .-main
	.ident	"GCC: (GNU) 3.3.3 (NetBSD nb3 20040520)"
