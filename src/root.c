#include "root.h"
#include "input.h"
#include <limits.h>

int num_degree=0;
int num_coeff[10];

float upp_lim=0;
float low_lim=0;

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
{   float i=0;
    float pos,temp=0;
    float min = 99999,up=0;

    for(i=-32768;i<=32768;i++)
    {
            pos = calculate(i);

            //printf("%f\t",pos);
            
            if(pos>0)
            {
                if(pos<min)
                {
                    min = pos;
                    up=i;
                }
            }   
    }
    //printf("%f",min);
    return up;
}

int interval_2()
{   float i=0;
    float temp=0;
    float neg=0, max = -99999;
    float low=0;
    for(i=-32768;i<=32768;i++)
    {
            neg = calculate(i);
          
            if(neg<0)
            {
                if(neg>max)
                {
                    max = neg;
                    low=i;
                }
            }             
    }
    return low;
}

float Bisection(float upp_lim,float low_lim)
{   
    float x1=0, roots=0,b=0;
    int itr, max_itr=20 ;
    for(itr=0;itr<=max_itr;itr++)
   {
       x1 = (upp_lim + low_lim)/2;
       roots = calculate(x1);

       {    
           if(roots>0)
            {
                upp_lim = x1;
            }
            else
            {
                low_lim = x1;
            }
       }

       if(roots-calculate((upp_lim+low_lim)/2)<=0.01)
       b = ((upp_lim+low_lim)/2);

       else 
       continue;

   } return b;
}

float root()
{   float r_o;
    accept_func();
    
    upp_lim = interval_1();
    low_lim = interval_2();
   
   r_o = Bisection(upp_lim,low_lim);

    printf("%f\t %f\n",upp_lim,low_lim);
    printf("%f",r_o);

}