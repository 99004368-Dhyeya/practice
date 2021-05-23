#include "input.h"
#include <math.h>

float trig_val(float x)
{
    if(nu==0)
    return 0;
    else if(nu==1)
    {
        float trig_val=ret_val(fun,x);
        return trig_val;
    }
    else if(nu==2)
    {
        int fun1=fun/10;int fun2=fun%10;
        float trigo_val=ret_val(fun1,x);
        if(ari==1)
        {
            trigo_val=trigo_val+ret_val(fun2,x);
        }
        else if(ari==2)
        {
            trigo_val=trigo_val-ret_val(fun2,x);
        }
        else if(ari==3)
        {
            trigo_val=trigo_val*ret_val(fun2,x);
        }
        else if(ari==4)
        {
            trigo_val=trigo_val/ret_val(fun2,x);
        }
        return trigo_val;

    }
}
float ret_val(int a,float x)
{
    if(a==1)
            return sin(x);
        else if (a==2)
            return cos(x);
        else if (a==3)
            return tan(x);
        else if (a==2)
            return log(x);
}
