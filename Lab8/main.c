#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student
{
    char school[10];
    int code;
    float grade;
};
typedef struct student AddStudent;
void readData(AddStudent *, int );
float average(AddStudent *, int, char *);
void BelowAverage(AddStudent *, int, float, char * );
int fixgrade(AddStudent*,int,float, int);

int main()
{
    int numOfStudents;
    AddStudent *st = NULL;
    printf("Enter the amount of students: \n");
    scanf("%d", &numOfStudents);
    st = (AddStudent *)malloc(numOfStudents*sizeof(AddStudent));
    if(st==NULL)
    {
        printf("Out of memory. Process terminated");
        return 0;
    }
    printf("Enter the students' data\n");
    r           eadData(st, numOfStudents);
    float averageofschool;
    char *checkschool;
    checkschool= (char *)malloc(10);
    averageofschool=average(st, numOfStudents, checkschool);
    BelowAverage(st, numOfStudents, averageofschool, checkschool);
    int StudentCode;
    float NewGrade;
    printf("Type in the code and the new grade:");
    scanf("%d %f", &StudentCode, &NewGrade);
    if (fixgrade(st, StudentCode, NewGrade, numOfStudents)==-1)
        printf("code not found");
    free(st);
    free(checkschool);
    return 0;
}
void readData(AddStudent *std, int nStudents)
{
    for (int i=0; i<nStudents; i++)
    {
        printf("\nStudent number %d\n\n", i+1);
        rintf("Student school: ");
        scanf("%s", &std[i].school);
        printf("Student code: " );
        scanf("%d", &std[i].code);
        printf("Student grade: ");
        scanf("%f", &std[i].grade);
    }
}

float average(AddStudent *std, int nStudents, char *input)
{
    float sum=0, k=0;
    printf("Please enter which school you want to check: \n");
    scanf("%s", input);
    for (int i=0; i<            nStudents; i++)
    {
        if (strcmp(input, &std[i].school)==0)
        {
            sum = sum + std[i].grade;
            k++;
        }
    }
    float avg=sum/k;
    printf      nThe average grade of %s, is %0.2f\n", input, avg);
    return avg;
}

void BelowAverage(AddStudent *std, int nStudents, float avg, char *school)
{
    printf("\nStudents in %s with grade below average:\n\n ", school);
    for (int i=0; i<nStudents; i++)
    {
        if(strcmp(school, &std[i].school)==0 && std[i].grade<avg)
            printf("Student code: %d, Student grade: %0.2f\n", std[i].code, std[i].grade);
    }
}

int fixgrade(AddStudent *std, int code,float newGrade, int nStudents)
{
    for (int i=0; i<nStudents; i++)
    {
        if(std[i].code==code)
        {
            std[i].grade=newGrade;
            return 0;
        }
    }
    return -1;
}
