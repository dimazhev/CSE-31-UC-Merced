
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct Node {
    int iValue;
    float fValue ;
    struct Node *next;
};

int main() {

    struct Node *head = (struct Node*) malloc(sizeof(struct Node));
    head->iValue = 5;
    head->fValue = 3.14;
    head->next = NULL;
	printf("Address of head is: %d", &head);
	printf("\nValue of Head is:%d",head);
printf("\nAddress of IValue is:%d",&head->iValue);
printf("\nAddress of FValue is:%d",&head->fValue);
printf("\nAddress of Next is:%d",&head->next);
	
	return 0;
}
