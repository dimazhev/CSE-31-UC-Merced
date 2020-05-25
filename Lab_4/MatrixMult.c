#include <stdio.h>
#include <stdlib.h>


int **matMult(int **a, int **b, int size){
int c,d,g,temp;
int** result;


result = (int**) malloc(size*sizeof(int*));
for (c=0; c<size; c++)
result[c] = (int*) malloc(size*sizeof(int));
result = (int**) malloc(size*sizeof(int*));

for (c=0; c<size; c++)
result[c] = (int*) malloc(size*sizeof(int));
for(c=0; c<size; c++)
{
for(d=0; d<size; d++)
{
temp = 0;
for(g=0; g<size; g++)
{
temp = temp + ((*(*(a + c) + g)) * (*(*(b + g) + d)));
}
*(*(result+c)+d) = temp;
}
}
return result;
}


void printArray(int **arr, int n)
{
// (2) Implement your printArray function here

for (int i = 0; i < n; i++)
{
for (int j = 0; j < n; j++)
{
printf("%d ", *(*(arr+i)+j));
}
printf("\n");
}
}



int main()
{

    int n = 0,i,j;
int **matA, **matB, **matC;

// (1) Define 2 n x n arrays (matrices).
    printf("\nEnter n value: ");
    scanf("%d", &n);

    
    matA = (int**) malloc(n*sizeof(int*));
    for (i=0; i<n; i++){
        matA[i] = (int*) malloc(n*sizeof(int));}
    
    matB = (int**) malloc(n*sizeof(int*));
    for (i=0; i<n; i++){
        matB[i] = (int*) malloc(n*sizeof(int));}

    
    matC = (int**) malloc(n*sizeof(int*));
    for (i=0; i<n; i++){
        matC[i] = (int*) malloc(n*sizeof(int));}

    printf("\n Enter %d numbers: ", (n*n));

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
    
            scanf("%d", (*(matA+i)+j));
    }
    }

    printf("\n Enter %d numbers again: ", (n*n));

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
    
            scanf("%d", (*(matB+i)+j));
    }
    }


// (3) Call printArray to print out the 2 arrays here.
printf("Matrix 1 :\n");
printArray(matA, n);
printf("Matrix 2 :\n");
printArray(matB, n);
//(5) Call matMult to multiply the 2 arrays here.
matC = matMult(matA, matB, n);
//(6) Call printArray to print out resulting array here.
printf("Result :\n");
printArray(matC, n);
return 0;
}

