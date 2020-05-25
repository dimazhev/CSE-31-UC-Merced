.data

str1:   .asciiz "Please enter an integer: "


.text
main:        #(display statement)
li $v0, 4
la $a0, str1
syscall

#(read user input)
li $v0, 5
syscall
move $a0, $v0        #store the user input in arguement register
addi $v0, $zero, 0   #clear $v0 since it will be used for return value

jal recursion         # Call recursion(x)

#(printing returned value)
add $a0, $v0, $0    #moving to $a0 since $v0 will be used for syscall
li $v0, 1
syscall

j end            # Jump to end of program


# Implementing recursion
recursion:    addi $sp, $sp, -8      #Push stack frame for local storage

sw $ra, 0($sp)            #storing return address of main in the stack

li $t0, 10                #checking value is ten
bne $a0, $t0, not_ten

addi $v0, $v0, 2          #if it is ten, then return 2 and end recur
j end_recur

not_ten:    li $t0, 11                #checking value is eleven
bne $a0, $t0, not_eleven

addi $v0, $v0, 1      #if it is ten, then return 1 and end recur
j end_recur

not_eleven:    sw $a0, 4($sp)           #store $a0 (m) in stack

addi $a0, $a0, 2      #new arguement: (m + 2)

jal recursion          #Call recursion (m + 2)

lw $a0, 4($sp)        #retrieving $a0 (m) from stack
addi $a0, $a0, 1      #new arguement: (m + 1)

jal recursion          # Call recursion (m + 1)

#(update returned value)
lw $t0, 4($sp)
add $v0, $v0, $t0

j end_recur


end_recur:        lw $ra, 0($sp)      #reloading main address

addi $sp, $sp, 8    # clear stack frame
jr $ra

end:        li $v0, 10          # Terminating the program
syscall

