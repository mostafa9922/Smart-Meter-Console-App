#include "main.h"
using namespace std;

void RMS_voltage_values_clc(double arr_v[], double arr_t[], int x)
{
    vector<double>intersection_index, intersection_time, frequency, region1, region2, region3, region_values;
    double v1,v2,v3,r1,r2,r3;
    for (int i = 0; i < x; i++)
    {
        if (arr_v[i] > 0 && arr_v[i + 1] < 0)
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
        if (frequency.at(i) < 49)
        {
            region1.push_back(intersection_index.at(i));
        }
    }

    for (int i = 0; i < frequency.size(); i++)
    {
        if (frequency.at(i) >= 49 && frequency.at(i) <= 51)
        {
            region2.push_back(intersection_index.at(i));
        }
    }

    for (int i = 0; i < frequency.size(); i++)
    {
        if (frequency.at(i) > 51)
        {
            region3.push_back(intersection_index.at(i));
        }
    }

   if(!region1.empty())
    {
        for(int i = region1.front(); i < region1.back(); i++)
        {
          v1 += pow(arr_v[i],2);
        }

        r1 = v1/(region1.back()-region1.front());
        cout << "For this region the RMS voltage value is  " << sqrt(r1) << " Volt" << endl;
    }


    if(!region2.empty())
    {
        for(int i = region2.front(); i < region2.back(); i++)
        {
        v2 += pow(arr_v[i],2);
        }
        r2 = v2/(region2.back()-region2.front());
        cout << "For this region the RMS voltage value is " << sqrt(r2) << " Volt" << endl;
    }

    if(!region3.empty())
    {
        for(int i = region3.front(); i < region3.back(); i++)
        {
        v3 += pow(arr_v[i],2);
        }
        r3 = v3/(region3.back()-region3.front());
        cout << "For this region the RMS voltage value is " << sqrt(r3) << " Volt" << endl;
    }
}





void RMS_current_values_clc(double arr_v[], double arr_t[], int x)
{
    vector<double>intersection_index, intersection_time, frequency, region1, region2, region3;
    double v1,v2,v3,r1,r2,r3;
    for (int i = 0; i < x; i++)
    {
        if (arr_v[i] > 0 && arr_v[i + 1] < 0)
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
        if (frequency.at(i) < 48)
        {
            region1.push_back(intersection_index.at(i));
        }
    }

    for (int i = 0; i < frequency.size(); i++)
    {
        if (frequency.at(i) >= 48 && frequency.at(i) <= 52)
        {
            region2.push_back(intersection_index.at(i));
        }
    }

    for (int i = 0; i < frequency.size(); i++)
    {
        if (frequency.at(i) > 52)
        {
            region3.push_back(intersection_index.at(i));
        }
    }

     if(!region1.empty())
    {
        for(int i = region1.front(); i < region1.back(); i++)
        {
          v1 += pow(arr_v[i],2);
        }

        r1 = v1/(region1.back()-region1.front());
        cout << "For this region the RMS Current value is  " << sqrt(r1) << " Amp" << endl;
    }


    if(!region2.empty())
    {
        for(int i = region2.front(); i < region2.back(); i++)
        {
        v2 += pow(arr_v[i],2);
        }
        r2 = v2/(region2.back()-region2.front());
        cout << "For this region the RMS Current value is " << sqrt(r2) << " Amp" << endl;
    }

    if(!region3.empty())
    {
        for(int i = region3.front(); i < region3.back(); i++)
        {
        v3 += pow(arr_v[i],2);
        }
        r3 = v3/(region3.back()-region3.front());
        cout << "For this region the RMS Current value is " << sqrt(r3) << " Amp" << endl;
    }
}

double RMS_current_clc(double arr[], int num)
{
    double sum = 0, avg;
    for (int i = 0; i < num; i++)
    {
        sum += pow(arr[i], 2);
    }
    avg = sum / num;
    return sqrt(avg);
}

double RMS_voltage_clc(double arr[], int num)
{
    double sum = 0, avg;
    for (int i = 0; i < num; i++)
    {
        sum += pow(arr[i], 2);
    }
    avg = sum / num;
    return sqrt(avg);
}
