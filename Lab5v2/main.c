#include <stdio.h>
#include <stdlib.h>

#define N 2

int CheckSymmetric(int matrix[N][N]);
int Mult(int matrix1[N][N], int matrix2[N][N], int result[N][N]);
int Transpose(int matrix[N][N], int matrixT[N][N]);
int printmatrix(int matrix[N][N]);
int main()
{
    int matrix1[N][N],matrix2[N][N],product[N][N],example[N][N];
    printf("Please type in the values of the first %d x %d matrix from left to right and top down:\n", N, N);
    for (int i=0; i<N; i++) {
            for (int k=0; k<N; k++) {
                scanf("%d", &matrix1[i][k]);
            }
    }
    printf("\nPlease type in the values of the second %d x %d matrix from left to right and top down:\n", N, N);
    for (int i=0; i<N; i++) {
            for (int k=0; k<N; k++) {
                scanf("%d", &matrix2[i][k]);
            }
    }
    printf("\nThe product of the two matrices is:\n");
    Mult(matrix1,matrix2,product);
    printmatrix(product);
    printf("\nThe transpose of the two matrices are:\n");
    int matrix1T[N][N],matrix2T[N][N];
    Transpose(matrix1, matrix1T);
    Transpose(matrix2, matrix2T);
    printmatrix(matrix1T);
    printf("\n");
    printmatrix(matrix2T);
    if (CheckSymmetric(matrix1)==1)
        printf("matrix1 is symmetric");
    else
        printf ("matrix1 is not symmetric");
    return 0;
}

int printmatrix(int matrix[N][N]) {
    for (int i=0; i<N; i++) {

        for (int k=0; k<N; k++)
            printf("%d ", matrix[i][k]);

        printf("\n");
    }

    return 0;
}

int Transpose(int matrix[N][N], int matrixT[N][N]) {
    for(int i=0; i<N; i++) {
        for (int k=0; k<N; k++) {
            matrixT[i][k]=matrix[k][i];
        }
    }
return ;
}

int Mult(int matrix1[N][N], int matrix2 [N][N], int result[N][N]) {
    for (int a=0; a<N; a++) {
        for (int b=0; b<N; b++) {
            int sum=0;
            for (int c=0; c<N; c++) {
                sum = sum + matrix1[a][c]*matrix2[c][b];
            }
            result[a][b]=sum;

        }
    }
}

int CheckSymmetric(int matrix[N][N]) {
    int matrixT[N][N];
    Transpose(matrix, matrixT);
    int x=0;
    for (int i=0; i<N; i++) {
        for (int k=0; k<N; k++) {

            if (matrix[i][k]==matrixT[i][k])
                continue;
            else
                x=N;
        }
        x++;
    }
        if (x==N)
            return 1;

    return 0;
}
