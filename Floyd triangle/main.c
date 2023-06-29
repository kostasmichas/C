#include <stdio.h>
#include <stdlib.h>

int main()
{
    int NumberOfLines;
    int a=1;

    do {
    printf("Type in the number of lines:\n");
    scanf("%d", &NumberOfLines);

    if (NumberOfLines <= 0)
            printf("Please enter a positive number\n");

    } while (NumberOfLines <= 0);

    for (int i=1; i <= NumberOfLines; i++) {
        for (int s= NumberOfLines; s > i; s--) {
                printf("    ");
        }

        for (int c=1; c <= i ; c++) {
                printf("%d " , a);
                a++;

        }
        printf("\n");
    }
    return 0;
}
