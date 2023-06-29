#include <stdio.h>
#include <stdlib.h>
int Menu(int x);
int fr_sum (int num1, int den1, int num2, int den2, int *numR, int *denR);
int fr_diff (int num1, int den1, int num2, int den2, int *numR, int *denR);
int fr_prod (int num1, int den1, int num2, int den2, int *numR, int *denR);
int fr_div (int num1, int den1, int num2, int den2, int *numR, int *denR);
int fr_rand (int *a, int *b);
int main()
{
    int Input;
    int a, c, b, d, e, f;
    do
    {
        Input=Menu(Input);
    }
    while(Input<1 || Input>4);

    fr_rand(&a, &b);
    fr_rand(&c, &d);
    if (Input==1)
    {
        fr_sum(a, b, c, d, &e, &f);
        printf("The sum of the fractions %d / %d + %d / %d = %d / %d",a ,b ,c ,d, e, f);
    }
    else if (Input==2)
    {
        fr_diff(a, b, c, d, &e, &f);
        printf("The difference of the fractions %d / %d - %d / %d = %d / %d", a ,b ,c ,d, e, f);
    }
    else if (Input==3)
    {
        fr_prod(a, b, c, d, &e, &f);
        printf("The product of the fractions is (%d / %d) * (%d / %d) = %d / %d", a ,b ,c ,d,  e, f);
    }
    else if (Input==4)
    {
        fr_div(a, b, c, d, &e, &f);
        printf("The quotient of the fractions is (%d / %d) / (%d / %d) = %d / %d", a ,b ,c ,d,  e, f);
    }
    return 0;
}

int Menu(int x)
{
    printf("Please choose an operation for your fractions:\n1)Addition\n2)Substraction\n3)Multiplication\n4)Division\n");
    scanf("%d", &x);
    return x;
}

int fr_sum(int num1, int den1, int num2, int den2, int *numR, int *denR)
{
    *numR=(num1*den2)+(num2*den1);
    *denR=(den1*den2);
    return 0;
}

int fr_diff(int num1, int den1, int num2, int den2, int *numR, int *denR)
{
    *numR=(num1*den2)-(num2*den1);
    *denR=(den1*den2);
    return 0;
}

int fr_prod(int num1, int den1, int num2, int den2, int *numR, int *denR)
{
    *numR=(num1*num2);
    *denR=(den1*den2);
    return 0;
}

int fr_div(int num1, int den1, int num2, int den2, int *numR, int *denR)
{
    while (num2==0)
    {
        num2 = -10 +rand()%(10-(-10)+1);
    }
    *numR=(num1*den2);
    *denR=(num2*den1);
    return 0;
}

int fr_rand(int *num, int *den) {
    *num = -10 +rand()%(10-(-10)+1);
    do {
    *den = -10 +rand()%(10-(-10)+1);
     } while (*den==0);

    return 0;

}
