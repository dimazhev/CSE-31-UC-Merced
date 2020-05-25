.data
    n: .word 25
    
    str1: .asciiz "Less than\n"
    str2: .asciiz "Less than or equal to\n"
    str3: .asciiz "Greater than\n"
    str4: .asciiz "Gretaer than or equal to\n"
   
    prompt: .asciiz "Enter an integer to compare: "

.text
    
    addi $v0,$0,4
    la $a0,prompt
    syscall
    
    addi $v0,$0,5
    syscall
    
    add $s0,$0,$v0
   
    lw $t0,n
    slt $t1,$s0,$t0
    beq $t1,1,gotoLess
    beq $s0,$t0,gotoGreaterEqual
    
    
    addi $v0,$0,4
    la $a0,str3
    syscall

end:
   addi $v0,$0,10
   syscall

gotoLess:
    beq $s0,$t0,gotoLessEqual
    addi $v0,$0,4
    la $a0,str1
    syscall
    j end

gotoGreaterEqual:
    addi $v0,$0,4
    la $a0,str2
    syscall
    j end

gotoLessEqual:
    addi $v0,$0,4
    la $a0,str4
    syscall
    j end

