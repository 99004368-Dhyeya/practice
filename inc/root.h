#include <stdio.h>
#include <math.h>
#include <string.h>

#ifndef __Root_H__
#define __Root_H__

extern float upp_lim;
extern float low_lim;

float root();

int interval_1();
int interval_2();
float Bisection(float,float);

#endif