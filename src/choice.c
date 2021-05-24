#include "input.h"
#include "root.h"

int choice()
{
int choice=0;
    printf("Enter choice for types of equations:\n");
    printf("Enter 1 for Algebraic Equations:\n");
    printf("Enter 2 for Transcedental Equations:\n");

    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        Algebraic();
        break;

        case 2:
        Transcedental();
        break;

        //case 3:
        //Newton_raphson();
    }
}