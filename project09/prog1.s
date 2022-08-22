# Name:		Yuliang Peng
# Directory ID: ypeng3
# UID:		118495965
# Section No:	0205

# -*- mode: text -*-


	.data

newline: .asciiz "\n"	
n:	.word 0
ans:	.word -1

	.text
main:	li	$v0, 5				# Read in three integers
	syscall
	move	$t0, $v0
	sw	$t0, n					# Store them in memory
	

	
	seq 	$t1, $t0, 0  		#Check if input is equal to 0

	sge		$t2,  $t0, 0		# Checks if input is greater than 0

	rem 	$t3, $t0 ,10 		# find the number for n %10 is not equal 0
	sne     $t4, $t3, 0 

	and     $t5, $t2, $t4 		# Check the and statment

	or  	$t6, $t1, $t5 		# Check the or statement

	beq 	$t6, 0, end			# Use if statment if not true then go to end

	li 		$t7, 0
	sw		$t7, ans


loop:  

	blez    $t0, end			# while (n > 0)

	mul		$t8, $t7, 10		# ans * 10
	rem		$t9, $t0, 10		# n % 10
	add		$t7, $t8, $t9		# add ans * 10 with n % 10
	sw		$t7, ans	

	div		$t0, $t0, 10
	sw		$t0, n

	
	j loop


end:
	
	li	$v0, 1				# print return value
	lw  $a0, ans
	syscall	

	la	$t1, newline  		# Print a newline character
	lw	$a0, ($t1)
	li	$v0, 11
	syscall

	li	$v0, 10				#finish the code 
	syscall
	
