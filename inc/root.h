#include <stdio.h>
#include <math.h>
#include <string.h>

#ifndef __Root_H__
#define __Root_H__

extern float upp_lim;
extern float low_lim;

float Algebraic();
float Transcedental();
float Newton_raphson();
float NR();
int interval_1();
int interval_2();
float Bisection(float,float);
float calculate1(float);
int choice();

#endif