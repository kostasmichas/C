#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PLATE_NUMBER 8

typedef struct violation {
    char number[PLATE_NUMBER];
    int code;
    float fee;
    struct violation *next;
} tViolation;

int Menu(int input);
void NewViolation(tViolation **, char number[PLATE_NUMBER], int, float);      //1
void PrintAll(tViolation *, int);                                            //2
float totalFee(tViolation *, char number[PLATE_NUMBER], int);                //3
int TotalViolations(tViolation *, int ,int);                                 //4
void deleteViolations(tViolation ** ,int ,char number[PLATE_NUMBER] ,int );   //5
                                                                             //Termination 6
void updateViolationsForPenalty(tViolation* ,int ,float ,int );

int main()
{
    int option;
    tViolation *head;
    head = (tViolation *)malloc(sizeof(tViolation));
    int nViolations=0;

    do {
        option=Menu(option);
        if (option==1){
            char pNumber[PLATE_NUMBER];
            int code;
            float fee;
            printf("\nPlease enter the: plate number, code of violation, fee of violation");
            scanf("%s %d %f", pNumber, &code, &fee);
            NewViolation(&head, pNumber, code, fee);
            nViolations++;
        }
        else if (option==2){
            PrintAll(head, nViolations);
            }

        else if (option==3){
            char input[PLATE_NUMBER];
            printf("Please enter the plate number of which's total fee you want to know :");
            scanf("%s", input);
            printf("\nThe total fee of %s is :%f", input, totalFee(head, input, nViolations));
        }
        else if (option==4){
            int code;
            printf("Please enter the code of the violation you want to check: \n");
            scanf("%d", &code);
            printf("The number of violations of the code %d are : %d", code, TotalViolations(head, code, nViolations));

        }
        else if(option==5) {
            if(nViolations==0){
                printf("There are no violations to delete.");
                continue;
            }
            int deletionCode;
            char deletionPlate[PLATE_NUMBER];
            printf("Enter the code and plate number of the violation you want to delete: ");
            scanf("%d %s", &deletionCode, deletionPlate);
            deleteViolations(&head, deletionCode, deletionPlate, nViolations);
            nViolations--;
        }
        else if(option==7){
            int newCode;
            float newFee;
            printf("Enter the code of the violation and the new fee: ");
            scanf("%d %f", &newCode, &newFee);
            updateViolationsForPenalty(head, newCode, newFee, nViolations);
        }
    }while (option!=6);
    printf("Process terminated by user");
    free(head);
    return 0;
}

int Menu(int input) {
    printf("\nPlease choose one of the following:\n1)Add a new violation.\n2)Print all violations.\n3)Sum of fees of a certain plate number.\n4)Check the amount of a specific violation.\n5)Delete a certain violation.\n6)End process.\n7)Update the fee for a violation code.\n");
    scanf("%d", &input);
    while (input<=0 || input>7){
        printf("Please enter a valid option");
        scanf("%d", &input);
    }
    return input;
}

void NewViolation(tViolation **first, char number[PLATE_NUMBER], int code, float fee) {
    tViolation *ptr;
    ptr=(tViolation *)malloc(sizeof(tViolation));
    ptr->code=code;
    ptr->fee=fee;
    strcpy(ptr->number, number);
    ptr->next=(*first);
    *first=ptr;
}

void PrintAll(tViolation *first, int numofv){
    if(numofv==0)
        printf("There are no saved violations. Please press 1 to add a new one.");
    tViolation *ptr=first;
    for(int k=0; k<numofv; k++){
        printf("\n Plate number: %s\nCode of violation: %d\nFee: %0.4f\n\n", ptr->number, ptr->code, ptr->fee);
        ptr=ptr->next;
    }
}

float totalFee(tViolation *first, char number[PLATE_NUMBER], int nViolations) {
    tViolation *ptr1=first;
    float sum=0;
    for (int i=0; i<nViolations; i++){
        if(strcmp(number, ptr1->number)==0) {
            sum=sum+ptr1->fee;
        }
        ptr1=ptr1->next;
    }
    return sum;
}

int TotalViolations(tViolation *first, int code, int nViolations){
    tViolation *ptr1=first;
    int viol=0;
    for(int i=0; i<nViolations; i++) {
        if(ptr1->code==code) {
            viol++;
        }
        ptr1=ptr1->next;
    }
    return viol;
}

void deleteViolations(tViolation **first, int code, char number[PLATE_NUMBER], int nViolations) {
    tViolation *ptr1, *ptr2;
    ptr1=(*first)->next;
    ptr2=(*first);
    for (int i=0; i<nViolations; i++){
        if (ptr1->code==code && strcmp(ptr1->number, number)==0) {
            ptr2->next=ptr1->next;
            free(ptr1);
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;

    }
}

void updateViolationsForPenalty(tViolation *first, int code, float fee, int nViolations) {
    tViolation *ptr=first;
    for (int i=0; i<nViolations; i++){
        if(ptr->code==code)
            ptr->fee=fee;
        ptr=ptr->next;
    }
}
