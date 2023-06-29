#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10
int main() {
    int n;
    printf("Please enter an integer from 1 to %d:\n", MAX_SIZE);
    scanf("%d", &n);
    int r=0;
    int product=n;
    for (r=0; r<=n; r++){
    for (int i=n-1; i>r; i--){
        product=product*i;
        printf("%d*", i);
    }

    printf("= %d\n", product);
    product=n;
    }

    return 0;
}


