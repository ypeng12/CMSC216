# Name:		Yuliang Peng
# Directory ID: ypeng3
# UID:		118495965
# Section No:	0205


# -*- mode: text -*-
#this program is tring to run the catalan number by assemby language
#the function main will read number from input and print out the result
#the function catalan will run the code by doing some calculations


	.data

newline: .asciiz "\n"	
number:	.word 0
result:	.word 0

	.text
main:	li	$sp, 0x7ffffffc 		# init $sp

	li	$v0, 5						# read in integer
	syscall
	move	$t0, $v0
	sw	$t0, number					# store it in number

	sw	$t0, ($sp)					# push arg onto stack
	sub	$sp, $sp, 4
	
	jal	catalan						# call catalan

	add	$sp, $sp, 4					# pop arg from stack

	sw	$v0, result					# store return value

	li	$v0, 1						# print return value
	lw	$a0, result
	syscall

	la	$t1, newline  				# Print a newline character
	lw	$a0, ($t1)
	li	$v0, 11
	syscall

	li	$v0, 10						# quit
	syscall

	
catalan:	
	sub	$sp, $sp, 16				# prologue
	sw	$ra, 16($sp)
	sw	$fp, 12($sp)
	add	$fp, $sp, 16

	li	$t0, -1						# ans = -1
	sw	$t0, 12($sp)

	lw	$t0, 4($fp)					# get arg "n" 

	bltz	$t0, ret				# if n < 0 , base case and return

	li	$t0, 1						# ans = 1
	sw	$t0, 12($sp)

	
	li	$t0, 1						# i = 1
	sw	$t0, 4($sp)

	j	loop						# otherwise, goto loop
	


loop:	


	lw 	$t0, 4($sp)					# get local variable i

	lw	$t1, 4($fp)					# get parameter n
	bgt	$t0, $t1, ret				# stop the loop if i > n

	
	lw	$t3, 12($sp)				# get ans


	mul $t4, $t0,2					#2 * i
	sub $t5, $t4, 1					#2 * i - 1
	mul $t6, $t5, 2					#2 * (2 * i - 1)
	mul $t7, $t6, $t3				#2 * (2 * i - 1) * ans
	add $t8, $t0, 1					#i + 1
	div $t9, $t7, $t8

	sw	$t9, 12($sp)


	lw	$t0, 4($sp)					# increment i
	add	$t0, $t0, 1
	sw	$t0, 4($sp)	

	j	loop						# repeat loop

ret:			
	lw	$v0, 12($sp)				# set return value to ans
	
	lw	$ra, 16($sp)				# epilogue
	lw	$fp, 12($sp)
	add 	$sp, $sp, 16
	jr	$ra
