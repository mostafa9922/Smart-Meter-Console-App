#include "main.h"

electrical_properites Low_pass_filter(double arr_c[],double arr_v[], double cutoff_angular_frequency, double t)
{
    electrical_properites array1;
    array1.current_f[0] = arr_c[0];
    array1.voltage_f[0] = arr_v[0];
    for (int index = 0; index < num_of_points - 1; index++)
    {
        array1.current_f[index + 1] = (array1.current_f[index] + (cutoff_angular_frequency * t * arr_c[index + 1])) / (1 + (cutoff_angular_frequency * t));
        array1.voltage_f[index + 1] = (array1.voltage_f[index] + (cutoff_angular_frequency * t * arr_v[index + 1])) / (1 + (cutoff_angular_frequency * t));
    }
    return array1;
}
