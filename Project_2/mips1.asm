.data
# Declare any necessary data here
str0: .asciiz "Welcome to BobCat Candy, home to the famous BobCat Bars!"
str1: .asciiz "\nPlease enter the price of a BobCat Bar:\n"
string1: .asciiz "Please enter the number of wrappers needed to exchange for a new bar:\n"
str2: .asciiz "How, how much do you have?\n"
str3: .asciiz "Good! let me run the number..."
str4: .asciiz "\nYou first buy "
str5: .asciiz " bars."
str6: .asciiz "\nThen, you will get another "
str7: .asciiz "\nWith $"
str8: .asciiz ", you will receive a maximum of "
str9: .asciiz " Bobcat Bars!"


.text

main:
       #This is the main program.
       #It first asks user to enter the price of each BobCat Bar.
       #It then asks user to enter the number of bar wrappers needed to exchange for a new bar.
       #It then asks user to enter how much money he/she has.
       #It then calls maxBars function to perform calculation of the maximum BobCat Bars
       # the user will receive based on the information entered.
       #It then prints out a statement about the maximum BobCat Bars the user will receive.
       addi $sp, $sp -4   # Feel free to change the increment if you need for space.
       sw $ra, 0($sp)
       li $t3,0
       # Implement your main here
       la   $a0, str0       # load address of str0 for syscall
       li   $v0, 4           # specify Print String service
       syscall
       la   $a0, str1       # load address of str1 for syscall
       li   $v0, 4           # specify Print String service
       syscall
       li $v0, 5
       syscall
       move $t0,$v0 #store user input in $t0
       la   $a0, string1       # load address of string1 for syscall
       li   $v0, 4           # specify Print String service
       syscall
       li $v0, 5
       syscall
       move $t1,$v0 #store user input in $t1
       la   $a0, str2       # load address of str2 for syscall
       li   $v0, 4           # specify Print String service
       syscall
       li $v0, 5
       syscall
       move $t2,$v0 #store user input in $t2
       la   $a0, str3       # load address of str3 for syscall
       li   $v0, 4           # specify Print String service
       syscall
       jal maxBars    # Call maxBars to calculate the maximum number of BobCat Bars
       # Print out final statement here
       j end           # Jump to end of program

maxBars:
       # This function calculates the maximum number of BobCat Bars.
       # It takes in 3 arguments ($a0, $a1, $a2) as n, price, and money. It returns the maximum number of bars
       div $t2,$t0
       mflo $s1
       mfhi $s2
       ble $s1,1,end
       la   $a0, str4      # load address of str4 for syscall
       li   $v0, 4           # specify Print String service
       syscall
       li $v0,1
       move $a0,$s1
       syscall
       move $t3,$s1
       la   $a0, str5      # load address of str5 for syscall
       li   $v0, 4           # specify Print String service
       syscall
       jal newBars    # Call a helper function to keep track of the number of bars.
       jr $ra
       # End of maxBars

newBars:
       # This function calculates the number of BobCat Bars a user will receive based on n.
       # It takes in 2 arguments ($a0, $a1) as number of wrappers left so far and n.
       div $s1,$t1
       mflo $s1
       mfhi $s4
       ble $s1,0,end
       la   $a0, str6       # load address of str6 for syscall
          li   $v0, 4           # specify Print String service
          syscall       
          li $v0,1
          move $a0,$s1
          syscall
          la   $a0, str5       # load address of str5 for syscall
          li   $v0, 4           # specify Print String service
          syscall
          add $t3,$t3,$s1
          add $s1,$s1,$s4
          j newBars
          jr $ra
          # End of newBars

end:
       la   $a0, str7       # load address of str7 for syscall
          li   $v0, 4           # specify Print String service
          syscall   
          li $v0,1
          move $a0,$t2
          syscall      
          la   $a0, str8       # load address of str8 for syscall
          li   $v0, 4           # specify Print String service
          syscall       
          li $v0,1
          move $a0,$t3
          syscall      
          la   $a0, str9       # load address of str9 for syscall
          li   $v0, 4           # specify Print String service
          syscall
          # Terminating the program
          lw $ra, 0($sp)
          addi $sp, $sp 4
           li $v0, 10
           syscall