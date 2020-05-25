#include <stdio.h>
#include <stdlib.h>

int sum(int m, int n);

int main(int argc, char **argv) {
    int m = 10;
    int n = 5;
    
    printf("%d\n", sum(m, n));
    
    return 0;
}
int sum(int m, int n){
    int result;
    result = m + n;
    return result;
}

