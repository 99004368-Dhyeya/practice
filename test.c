#include"input.h"
#include"unity.h"
#include"unity_internals.h"
#include"root.h"


void setUp()
{

}
void tearDown()
{

}

double test_Bisection1(float x)
{
    num_degree=3;
    num_coeff[3]=5;
    num_coeff[2]=-5;
    num_coeff[1]=6;
    num_coeff[0]=-2;

    double return_value=(Algebraic(x));
    return return_value;
}

/*double test_Bisection2(float x)
{
    num_degree=3;
    num_coeff[3]=5;
    num_coeff[2]=-5;
    num_coeff[1]=6;
    num_coeff[0]=-2;
    str = cos;

    double return_value=(Transcedental(x));
    return return_value;
}*/

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_Bisection1);
   //3 RUN_TEST(test_Bisection2);
}
