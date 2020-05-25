.data
# Declare any necessary data here
str0: .asciiz "Welcome to BobCat Candy, home to the famous BobCat Bars!"
str1: .asciiz "\nPlease enter the price of a BobCat Bar:\n"
str2: .asciiz "Please enter the number of wrappers needed to exchange for a new bar:\n"
str3: .asciiz "How, how much do you have?\n"
str4: .asciiz "Good! let me run the number..."
str5: .asciiz "\nYou first buy "
str6: .asciiz " bars."
str7: .asciiz "\nThen, you will get another "
str8: .asciiz "\nWith $"
str9: .asciiz ", you will receive a maximum of "
str10: .asciiz " Bobcat Bars!"


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
       la   $a0, str0       
       li   $v0, 4           
       syscall
       la   $a0, str1       
       li   $v0, 4           
       syscall
       li $v0, 5
       syscall
       add $t0,$v0, $zero 
       la   $a0, str2      
       li   $v0, 4           
       syscall
       li $v0, 5
       syscall
       add $t1,$v0, $zero 
       la   $a0, str3       
       li   $v0, 4         
       syscall
       li $v0, 5
       syscall
       add $t2,$v0, $zero 
       la   $a0, str4       
       li   $v0, 4          
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
       la   $a0, str5      
       li   $v0, 4          
       syscall
       li $v0,1
       add $a0,$s1, $zero
       syscall
       move $t3,$s1
       la   $a0, str6     
       li   $v0, 4           
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
       la   $a0, str7       
     	  li   $v0, 4           
          syscall       
          li $v0,1
          add $a0,$s1, $zero
          syscall
          la   $a0, str6       
          li   $v0, 4          
          syscall
          add $t3,$t3,$s1
          add $s1,$s1,$s4
          j newBars
          jr $ra
          # End of newBars

end:
       la   $a0, str8       
          li   $v0, 4           
          syscall   
          li $v0,1
          add $a0,$t2, $zero
          syscall      
          la   $a0, str9      
          li   $v0, 4           
          syscall       
          li $v0,1
          add $a0,$t3, $zero
          syscall      
          la   $a0, str10       
          li   $v0, 4          
          syscall
          # Terminating the program
          lw $ra, 0($sp)
          addi $sp, $sp 4
           li $v0, 10
           syscall
