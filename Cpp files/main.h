// main.h file
#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>



using namespace std;

const int num_of_points = 10800001; // 10800001 For home file or  500001 for loads
const int num_of_loads = 1;

class home_appliances
{
public:
    // getter section
    string get_name()
    {
        return l_name;
    }
    double get_max_current()
    {
        return max_current;
    }
    double get_max_voltage()
    {
        return max_voltage;
    }
    bool get_status()
    {
        return status;
    }
    double get_consumption_time()
    {
        return consumption_time;
    }
    // setter section
    void set_name(string inti_name)
    {
        l_name = inti_name;
    }
    void set_max_current(double cmax)
    {
        max_current = cmax;
    }
    void set_max_voltage(double vmax)
    {
        max_voltage = vmax;
    }
    void set_status(bool s)
    {
        status = s;
    }
    void set_consumption_time(double t)
    {
        consumption_time = t;
    }

private:
    string l_name;
    double max_current = 10;
    double max_voltage = 400;
    double consumption_time;
    int status;

};

struct electrical_properites
{
    double current[num_of_points];
    double voltage[num_of_points];
    double voltage_f[num_of_points];
    double current_f[num_of_points];
    double time[num_of_points];
    double power[num_of_points];
    double active_power, energy, traiff, apparent_power, power_factor, rms_current, rms_voltage, average_power;
};


#endif // MAIN_H_INCLUDED
