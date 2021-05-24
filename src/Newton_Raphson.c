#include "root.h"
#include "input.h"
#include <limits.h>

double calculate1(float x)
{   int y = num_degree;
    for(int i=0;i<=num_degree;i++)
    {
        num_co[i] = y * num_coeff[i];
        y--;
    }
    double num_val=0;
    num_degree--;
    for(int i=num_degree;i>=0;i--)
    {
        //printf("%d\n",num_coeff[i]);
        num_val=num_val+(num_co[i]*power(x,i));
        //printf("%f\n",num_val);
    } 
    num_val=num_val+trig_val(x);
    return num_val;
}

double NR()
{   double val=0;
    int i=0,itr=0;
    for(itr=0;itr<=num_degree;itr++)
   {   
       if(calculate1(val)!=0)
       {
       val = val - (calculate(val)/calculate1(val));
       }         
   }
   return val;
}
double Newton_raphson()
{
    double r_o=0;
    accept_func();
    //trig_input();

    r_o = NR();
    printf("%f",r_o);
}