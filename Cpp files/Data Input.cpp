// Data Input.cpp file

#include "main.h"
electrical_properites read_from_csv(string L_path)
{
    electrical_properites array1;
    ifstream myfile1;
    string time1, wave1, wave2;
    myfile1.open(L_path);
    for (int i = 0; i < num_of_points; i++)
    {
        getline(myfile1, time1, ',');
        array1.time[i] = stod(time1);
        getline(myfile1, wave1, ',');
        array1.voltage[i] = stod(wave1);
        getline(myfile1, wave2, '\n');
        array1.current[i] = stod(wave2);
    }
    return array1;
}
