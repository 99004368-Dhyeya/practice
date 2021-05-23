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
{   int count1;
    float pos=0;
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
{   int count2=0;
    float neg=0;
    while(1)
    {
            neg = calculate(count2);
          
            if(neg<0)
            {break;}

            count2--;      
    }
    return neg;
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
    //float x = calculate(3);
    upp_lim = interval_1();
    low_lim = interval_2();
   
   r_o = Bisection(upp_lim,low_lim);

    printf("%f",r_o);

}