#include "root.h"
#include "input.h"
#include <limits.h>
#include "plotfunctions.h"

double upp_lim=0;
double low_lim=0;



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



double Algebraic()
{   double r_o=0;
    
    accept_func();
    
    upp_lim = interval_1();
    low_lim = interval_2();
   
   r_o = Bisection(upp_lim,low_lim);

    printf("%lf\t %lf\n",upp_lim,low_lim);
    printf("%lf\n",r_o);
    

}

double Transcedental()
{
    double r_o=0;
    accept_func();
    trig_input();
    upp_lim = interval_1();
    low_lim = interval_2();
   
   r_o = Bisection(upp_lim,low_lim);

    printf("%lf\t %lf\n",upp_lim,low_lim);
    printf("%lf\n",r_o);
}

