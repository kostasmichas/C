#include <stdio.h>
#include <stdlib.h>
//Michalochristas Konstantinos AM: 2020030111
struct fraction {
    int numerator;
    int denominator;
};

typedef struct fraction Fr;

void ReadFractions(Fr * ,int );
Fr FractionMultiplication(Fr *, int);
void PrintMultiplication(Fr *, Fr, int);
int main()
{
    int nFr;
    Fr *FrArr;
    do {
    printf("Enter the number of fractions you want to multiply (Press 0 to end the program): ");
    scanf("%d", &nFr);
    if(nFr==0)
        break;
    FrArr=(Fr *)malloc(nFr*sizeof(Fr));
    ReadFractions(FrArr, nFr);
    Fr ResultOfMultiplication;
    ResultOfMultiplication=FractionMultiplication(FrArr, nFr);
    PrintMultiplication(FrArr, ResultOfMultiplication, nFr);
    } while (1);
    free(FrArr);
    return 0;
}

void ReadFractions(Fr *Array, int numoffractions) {
    for (int i=0; i<numoffractions; i++) {
        printf("\nEnter numerator and denominator for fraction number %d :", i+1);
        scanf("%d %d", &(Array[i].numerator), &(Array[i].denominator));
        while (Array[i].denominator==0) {
            printf("The denominator you entered is invalid. Please type a new one: ");
            scanf("%d", &(Array[i].denominator));
        }
    }
}

Fr FractionMultiplication(Fr *Array, int numoffractions){
    Fr Result;
    int numeratorProduct=1;
    int denominatorProduct=1;
    for (int i=0; i<numoffractions; i++) {
        numeratorProduct=numeratorProduct*(Array[i].numerator);
        denominatorProduct=denominatorProduct*(Array[i].denominator);
    }
    Result.numerator=numeratorProduct;
    Result.denominator=denominatorProduct;
    return Result;
}

void PrintMultiplication(Fr *Array, Fr Result, int numoffractions){
    for(int i=0; i<numoffractions; i++){
        if (i!=numoffractions-1)
            printf("(%d/%d)*", Array[i].numerator, Array[i].denominator);
        else
            printf("(%d/%d)", Array[i].numerator, Array[i].denominator);
    }
    printf("=%d/%d\n", Result.numerator, Result.denominator);
}
