#include "root.h"
#include "input.h"

int num_degree=0;
int num_coeff[10];

int upp_lim=0;
int low_lim=0;

void accept_func()
{
    printf("Enter max degree of variable 'x' in the numerator and denominator\n");
    scanf("%d",&num_degree);

    printf("Enter numerator function coefficients, starting from the max degree term and ending with the constant\n");
    char temp;
    int i=num_degree;
    do
    {
        scanf("%d%c",&num_coeff[i],&temp);
        i--;
    } while (temp!='\n');
    
}

float power(float x, int deg)
{
    if(deg==0)
        return 1;
    else
    {
        float value=1;
        for(int i=1;i<=deg;i++)
        value=value*x;
        return value;
    }
}
float calculate(float x)
{
    float num_val=0;
    for(int i=num_degree;i>=0;i--)
    {
        //printf("%d\n",num_coeff[i]);
        num_val=num_val+(num_coeff[i]*power(x,i));
        //printf("%f\n",num_val);
    }
    
    //num_val=num_val+trig_val(x);
    return num_val; //return value to be checked

}

int interval_1()
{
    int count1=0,pos=0;
    while(1)
    {
            pos = calculate(count1);

            //printf("%d",pos);
            
            if(pos>0)
            {break;}
      count1++;
    }
    return pos;
}
int interval_2()
{
    int neg=0,count2=0;
    while(1)
    {
            neg = calculate(count2);
          
            if(neg<0)
            {break;}

            count2--;      
    }
    return neg;
}

/*Bisection(int upp_lim,int low_lim)
{

    return r_o;
}*/

float root()
{   
    accept_func();
    upp_lim = interval_1();
    low_lim = interval_2();
   
   //r_o = Bisection(upp_lim,low_lim);

    printf("%f\n%f",upp_lim,low_lim);

}