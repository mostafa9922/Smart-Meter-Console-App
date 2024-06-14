#include"main.h"
electrical_properites power_arr_clc(double arr_c[], double arr_v[], int x)
{
    electrical_properites p ;
    for(int i = 0; i < x; i++)
    {
        p.power[i] = arr_c[i] * arr_v[i];
    }
    return p;
}

// power Function
double active_power_clc(double arr1[])
{
    double sum = 0;
    for (int i = 0; i < num_of_points; i++)
    {
        sum += arr1[i];
    }
    return sum / num_of_points;
}

void power_show(double arr_p[], double arr_t[], int x)
{
    vector<double> intersection_index, intersection_time, frequency, region1, region2, region3, region_values;
    double p1,p2,p3;
    for (int i = 0; i < x; i++)
    {
        if (arr_p[i] > 0 && arr_p[i + 1] < 0)
        {
            intersection_time.push_back(arr_t[i]);
            intersection_index.push_back(i);
        }
    }

    for (int j = 0; j < intersection_time.size() - 1; j++)
    {
        frequency.push_back(1 / (intersection_time.at(j + 1) - intersection_time.at(j)));
    }

    for (int i = 0; i < frequency.size(); i++)
    {
        if (frequency.at(i) < 98)
        {
            region1.push_back(intersection_index.at(i));
        }
    }

    for (int i = 0; i < frequency.size(); i++)
    {
        if (frequency.at(i) >= 98 && frequency.at(i) <= 102 )
        {
            region2.push_back(intersection_index.at(i));
        }
    }

    for (int i = 0; i < frequency.size(); i++)
    {
        if (frequency.at(i) > 102)
        {
            region3.push_back(intersection_index.at(i));
        }
    }

    if(!region1.empty())
    {
        for(int i = region1.front(); i < region1.back(); i++)
        {
        p1 += arr_p[i] ;
        }
        cout << "For previous region the active power is  " << p1/(region1.back()-region1.front()) << " Watt" << endl;
    }


    if(!region2.empty())
    {
        for(int i = region2.front(); i < region2.back(); i++)
        {
        p2 += arr_p[i];
        }
        cout << "For previous region the active power is " << p2/(region2.back()-region2.front()) << " Watt" << endl;
    }

    if(!region3.empty())
    {
        for(int i = region3.front(); i < region3.back(); i++)
        {
        p3 += arr_p[i];
        }
        cout << "For previous region the active power is " << p3/(region3.back()-region3.front()) << " Watt" << endl;
    }

}

double apparent_power_clc (double rms1, double rms2)
{
    return rms1 * rms2;
}

