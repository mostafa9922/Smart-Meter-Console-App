#ifndef PROTECTION_ALARMS_H_INCLUDED
#define PROTECTION_ALARMS_H_INCLUDED
#include "main.h"

void Alert_for_current(double arr_c[], double arr_t[], int x, double C_max);
void Alert_for_voltage(double arr_c[], double arr_t[], int x, double C_max);



#endif // PROTECTION_ALARMS_H_INCLUDED
