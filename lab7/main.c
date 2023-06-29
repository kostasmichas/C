#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MIN 5
#define MAX 20
#define FIRST_CHAR 'a'
#define LAST_CHAR 'z'
#define NULL_CHAR '\0'
char *readInputString(char*);
void printStrings(char **strArray, int strArraySize);
void sort(char **strArray, int strArraySize);
void swap(char **, char **);
int main()
{
    srand(time(NULL));
    char **str;
    int n;
    printf("Type in how many strings you want: \n");
    scanf("%d", &n);
    str =(char **) malloc(n*sizeof(char *));

    for(int i=0; i<n; i++)
    {
        str[i]= malloc(MAX+1);
        str[i]=randomString(MIN, MAX);
    }
    printf("\nThe %d random strings are:\n", n);
    printStrings(str, n);

    printf("\n\nThe %d random strings sorted with alphabetical order are: \n", n);
    sort(str, n);
    printStrings(str, n);
    for(int i=0; i<n; i++)
        free(str[i]);
    free(str);
    return 0;
}

void printStrings(char **strArray, int strArraySize)
{
    for (int i=0; i<strArraySize; i++)
    {
        printf("\n%s", strArray[i]);
    }
}
char *readInputString(char *str)
{
    char buffer[MAX];
    char *newStr;
    strcpy(buffer, str);
    newStr=(char *)malloc(strlen(buffer)+1);
    newStr=buffer;
    return buffer;
}

void sort(char **strArray, int strArraySize)
{
    int j, i;
    for (j=0; j<strArraySize; j++){
        for(i=j+1; i<strArraySize; i++)
            if (strcmp(strArray[i], strArray[j])==-1){
                swap(&strArray[j], &strArray[i]);
            }
    }
}

void swap(char **a, char **b) {
    char *temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
