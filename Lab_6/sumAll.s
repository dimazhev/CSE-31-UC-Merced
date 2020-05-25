.data
prompt2 : .asciiz "\nEnter an integer (Enter 0 if done entering integers) : "
pos_sum : .asciiz "\nThe sum of positive numbers is : "
neg_sum : .asciiz "\nThe sum of negative numbers is : "

.text
li $s0,0 
li $s1,0 

loop:
li $v0,4
la $a0,prompt2 
syscall

li $v0,5
syscall       
move $t0,$v0

beqz $t0,done

bltz $t0,negativeNum 
add $s0,$s0,$t0 
j skip
negativeNum:
add $s1,$s1,$t0 
skip:
j loop
done:

li $v0,4
la $a0,pos_sum
syscall
move $a0,$s0
li $v0,1
syscall

li $v0,4
la $a0,neg_sum 
syscall
move $a0,$s1
li $v0,1
syscall