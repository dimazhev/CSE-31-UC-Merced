.text
.globl main
main:
li $s0,5 
li $s1,10

move $a0,$s0
move $a1,$s1 
jal sum

add $s1,$s1,$v0 
add $s1,$s1,$s0 
li $v0,1
move $a0,$s1
syscall 
li $v0,10 
syscall

sum:
addi $sp, $sp, 4
subu $sp,$sp,4 
sw $ra,($sp) 

move $t1, $a0 
move $t2, $a1 

add $a0,$t2,1 
add $a1,$t1,1 
jal sub
move $t3,$v0 

sub $a0,$t1,1 
sub $a1,$t2,1 
jal sub
move $t4,$v0 

add $v0,$t3,$t4 
lw $ra,($sp) 
addu $sp,$sp,4 
addi $sp, $sp, 4
jr $ra

sub:
sub $v0,$a1,$a0 
jr $ra