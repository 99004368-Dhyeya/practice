#include <stdio.h>
#include <math.h>
#include <string.h>

#ifndef __Root_H__
#define __Root_H__

extern double upp_lim;
extern double low_lim;

double Algebraic();
double Transcedental();
double Newton_raphson();
double NR();
int interval_1();
int interval_2();
double Bisection(float,float);
double calculate1(float);
int choice();

#endif