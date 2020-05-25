#include <stdio.h>
int main(){
int n, typo;

printf("Enter the number of lines for punishment:");
scanf("%d",&n);

if (n<=0)
printf("You entered an incorrect value for the number of lines!");


else{

	printf("Enter the line you want to make a typo:");
	scanf("%d", &typo);

	if (typo < 0 || typo > n)
		printf("You entered an incorrect value for the line typo!");

else{
	for (int i = 1; i<=n; i++){
		if (i!=typo)
			printf("C Programming language is the best!");
		else printf("C programming language is the bet!");

}
}
	

}
 return 0;
}
