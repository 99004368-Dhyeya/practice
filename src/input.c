#include "root.h"
#include "input.h"
#include <limits.h>

int num_degree=0;
int num_coeff[10];
int num_co[10];

void accept_func()
{
    printf("Enter max degree of variable 'x'\n");
    scanf("%d",&num_degree);

    printf("Enter function coefficients, starting from the max degree term and ending with the constant\n");
    char temp;
    int i=num_degree;
    do
    {
        scanf("%d%c",&num_coeff[i],&temp);
        i--;
    } while (temp!='\n');
    
}

double power(double x, int deg)
{
    if(deg==0)
        return 1;
    else
    {
        double value=1;
        for(int i=1;i<=deg;i++)
        value=value*x;
        return value;
    }
}
double calculate(double x)
{
    double num_val=0;
    for(int i=num_degree;i>=0;i--)
    {
        //printf("%d\n",num_coeff[i]);
        num_val=num_val+(num_coeff[i]*power(x,i));
        //printf("%f\n",num_val);
    }
    
    num_val=num_val+trig_val(x);
    return num_val; //return value to be checked

}