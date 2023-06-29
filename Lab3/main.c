#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Number,d=0,c=1,sum,e=10,b,f,upper,lower;
    int d=0; //ο αριθμος ψηφιων//
    int c=1; //μεταβλητη για την βοηθεια ευρεσης του d//
    int sum; //το τελικο αθροισμα/
    int e=10; //μεταβλητη για την βοηθεια ευρεσης του b//
    int b;  //μεταβλητη για να ξεχωρισουμε τα ψηφια ενα προς ενα//
    int f;  // μεταβλητη για την βοηθεια υψωσης σε δυναμη//
    int upper, lower;

    printf("Please enter an upper and lower bound:");
    scanf("%d %d", &upper, &lower);
    Number=lower;
    printf("The armstrong numbers are:\n");
    for (Number=lower; Number<=upper; Number++){

//Γνωριζουμε οτι η προταση ισχυει για καθε αριθμο μικροτερο η ίσο του 9 και οτι δεν ισχυει για αρνητικους αριθμους οποτε://




//Ο παρακατω βροχος υπολογιζει το πληθος των ψηφιων που εχει ο αριθμος //


    while (Number/c>0) {
            c=10*c;
            d++;

    }

//Ο επομενος βροχος ξεχωριζει τα ψηφια του αριθμου απο τα δεξια προς τα αριστερα,επειτα ο φωλιασμενος βροχος τα υψωνει στην δυναμη απο τον αριθμο των ψηφιων και τελος ο αριθμος προστιθεται σε ενα sum//

    for (int a=0; a<d; a++) {

                b=(Number%e)/(e/10);
                f=b;

                //βροχος για να υψωσουμε σε δυναμη//
           for (int i=0; i<d-1; i++) {
            b=b*f;
           }

           sum = sum + b;
           e=10*e;

    }

    //Η εκτυπωση της καταλληλης φρασης//
    if (sum==Number)
        printf("%d ", Number);
    else
        continue;

    }


    return 0;

}


