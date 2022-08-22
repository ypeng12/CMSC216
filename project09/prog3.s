# Name:		Yuliang Peng
# Directory ID: ypeng3
# UID:		118495965
# Section No:	0205

# -*- mode: text -*-
#this program is tring to run the catalan number by assemby language
#the function main will read number from input and print out the result
#the catalan is recursive, it will have temp number and answer return answer


	.data

newline: .asciiz "\n"	
number:	.word 0
result:	.word 0

	.text
main:	li	$sp, 0x7ffffffc		 # init $sp

	li	$v0, 5					# read in integer
	syscall
	move	$t0, $v0
	sw	$t0, number				# store it in number

	sw	$t0, ($sp)				# push arg onto stack
	sub	$sp, $sp, 4
	
	jal	catalan					# call catalan

	add	$sp, $sp, 4				# pop arg from stack

	sw	$v0, result				# store return value

	li	$v0, 1					# print return value
	lw	$a0, result
	syscall

	la	$t1, newline  			# Print a newline character
	lw	$a0, ($t1)
	li	$v0, 11
	syscall

	li	$v0, 10					# quit
	syscall
	
catalan:	
	sub	$sp, $sp, 20			# prologue
	sw	$ra, 20($sp)
	sw	$fp, 16($sp)
	add	$fp, $sp, 20

	li	$t0, -1					# ans = -1
	sw	$t0, 12($sp)
		
	lw	$t1, 4($fp)				# get parameter n

	beqz	$t1, assi			# if n == 0 , base case and return

	j	else					# go to loop

assi:

	li	$t0, 1					# ans = 1
	sw	$t0, 12($sp)
	
	j ret
	
else:

	lw	$t1, 4($fp)				# get parameter n

	ble	$t1,0, ret				# if n <= 0


	lw	$t0, 4($fp)				# get n
	sub	$t0, $t0, 1				# compute n - 1

	sw	$t0, ($sp)				# push n - 1 onto stack
	sub	$sp, $sp, 4
	
	jal	catalan	
	add	$sp, $sp, 4				# pop the arg from the stack
	
	sw	$v0, 8($sp)


	lw	$t0, 4($fp)				#get n
	lw	$t1, 8($sp)				#get temp
	lw	$t3, 12($sp)			# get ans


	mul $t4, $t0,2  			# 2 * n


	sub $t5, $t4, 1				#2 * n -1
	mul $t6, $t5, 2				#2 * (2 * n - 1)
	mul $t7, $t6, $t1			#(2 * (2 * n - 1) * temp)
	add $t8, $t0, 1
	div $t9, $t7, $t8

	sw	$t9, 12($sp)



	j ret


ret:			
	lw	$v0, 12($sp)			# set return value to ans
	
	lw	$ra, 20($sp)			# epilogue
	lw	$fp, 16($sp)
	add 	$sp, $sp, 20
	jr	$ra
