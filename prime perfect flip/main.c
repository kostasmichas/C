#include <stdio.h>
#include <stdlib.h>

/*This function flips the number*/

int flip (int x) {
    int d=0;
    int i=1;
    int sum=0;
    while (x/i>0) {
        d++;
        i=10*i;
    }
    i=10;
    for (d; d>0; d--) {
        int y=x%i;
        for (int k=d-1; k>0; k--) {
            y=y*10;
        }
        sum = sum + y;
        x=x/10;
        }
        printf("%d ", sum);
        return x;
    }

/*This function checks if the number is perfect*/

int CheckPerfect(int x) {
    int y;
    int sum=0;
    for (int i=x-1; i>0; i--) {
        y=x%i;
        if (y==0)
            sum=sum + i;
        else
            continue;
    }
    if (sum==x)
        printf("%d ", x);

    return x;
}

/*This function asks for a number from the user and returns it*/

int readNumber(int x, int y)   {
    while (x<=0 || y<=0) {
        printf("Only positive integers. Try again\n");
        scanf("%d", &x);
    }
    return x;
}

/*This function checks if the number is prime*/

int CheckPrime(int x) {
    int i;
    int y;
    for (i=x-1; i>1; i--) {
        y=x%i;
        if (y==0)
            break;
        else
            continue;
    }
    if (y!=0)
        printf("%d ", x);

    return x;
}


int main()
{
    int lower, upper;
    printf("Please enter a lower and upper bound\n");
    scanf("%d %d", &lower, &upper);
    readNumber(lower, upper);
    printf("The prime numbers in [%d,%d]:\n", lower, upper);
    for (int Number=lower; Number<=upper; Number++)
        CheckPrime(Number);
    printf("\nThe perfect numbers in [%d.%d]:\n", lower, upper);
    for (int Number=lower; Number<=upper; Number++)
        CheckPerfect(Number);
    printf("\nThe flipped numbers in [%d,%d]:\n", lower, upper);
    for (int Number=lower; Number<=upper; Number++)
        flip(Number);
    return 0;
}
