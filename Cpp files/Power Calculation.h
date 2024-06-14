#ifndef POWER_CALCULATION_H_INCLUDED
#define POWER_CALCULATION_H_INCLUDED
#include"main.h"
electrical_properites power_arr_clc(double arr_c[], double arr_v[], int x);
void power_show(double arr_p[], double arr_t[], int x);
double apparent_power_clc (double rms1, double rms2);
double active_power_clc(double arr1[]);



#endif // POWER_CALCULATION_H_INCLUDED
