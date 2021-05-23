#include <stdio.h>
#include <math.h>
#include <string.h>

#ifndef __INPUT_H__
#define __INPUT_H__

extern int num_degree;  //root variables
extern int num_coeff[];
float trig_val(float);

extern int nu;  //trig_val variables
extern int ari;
extern int fun;
extern char str[];

void accept_functwo();
float power(float, int);
float calculate(float);

void trig_input();  //trig functions
float trig_val(float);
float ret_val(int,float);



#endif