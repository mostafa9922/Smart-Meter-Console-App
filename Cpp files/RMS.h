#ifndef RMS_H_INCLUDED
#define RMS_H_INCLUDED
#include <vector>
double RMS_current_clc(double arr1[], int );

void RMS_voltage_values_clc(double arr_c[], double arr_t[], int x);
void RMS_current_values_clc(double arr_c[], double arr_t[], int x);


double RMS_voltage_clc(double arr[], int num);
double apparent_power_clc (double rms1, double rms2);




#endif // RMS_H_INCLUDED
