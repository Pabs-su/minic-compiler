.data
_i: .word 0
_j: .word 0
$str1: .asciiz "ERROR: Esto no debe imprimir\n"
$str2: .asciiz "EXITO: Else colgante resuelto bien\n"
$str3: .asciiz "Iteracion i: "
$str4: .asciiz "\n"
$str5: .asciiz "  Haciendo break en j=1\n"
.text
.globl main
main:
	li $t0, 0
	sw $t0, _i
	li $t0, 1
	li $t1, 0
	sgt $t2, $t0, $t1
	beqz $t2, l2
	li $t0, 0
	li $t1, 1
	sgt $t3, $t0, $t1
	beqz $t3, l0
	la $a0, $str1
	li $v0, 4
	syscall
	b l1
l0:
	la $a0, $str2
	li $v0, 4
	syscall
l1:
l2:
l7:
	lw $t0, _i
	li $t1, 3
	slt $t2, $t0, $t1
	beqz $t2, l3
	la $a0, $str3
	li $v0, 4
	syscall
	lw $t0, _i
	move $a0, $t0
	li $v0, 1
	syscall
	la $a0, $str4
	li $v0, 4
	syscall
	li $t0, 0
	sw $t0, _j
l6:
	lw $t0, _j
	li $t1, 1
	seq $t3, $t0, $t1
	beqz $t3, l5
	la $a0, $str5
	li $v0, 4
	syscall
	b l4
l5:
	lw $t0, _j
	li $t1, 1
	add $t3, $t0, $t1
	sw $t3, _j
	lw $t0, _j
	li $t1, 5
	slt $t3, $t0, $t1
	bnez $t3, l6
l4:
	lw $t0, _i
	li $t1, 1
	add $t3, $t0, $t1
	sw $t3, _i
	b l7
l3:
	li $v0, 10
	syscall
