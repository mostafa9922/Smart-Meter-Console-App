#include "main.h"
void Alert_for_current(double arr_c[], double arr_t[], int x , double max1)
{
    vector<double> intersection_index, intersection_time,time_max_region,time_natural_region;

    for (int i = 0; i < x; i++)
    {
        if ( (arr_c[i] > max1 && arr_c[i - 1] < max1) || (arr_c[i ] > max1 && arr_c[i + 1] < max1)  )
        {
            intersection_time.push_back(arr_t[i]);
            intersection_index.push_back(i);
        }
    }

    for(int j = 0; j < intersection_time.size() - 1; j +=2 )
    {
        time_max_region.push_back(intersection_time.at(j + 1) - intersection_time.at(j));
    }

    for(int k = 1; k < intersection_time.size() - 1; k+=2)
    {
        time_natural_region.push_back(intersection_time.at(k+1) - intersection_time.at(k));
    }

    cout << "\x1b[31mIn the following region from " << intersection_time.front() << " Sec to " << intersection_time.back() << " Sec the current is over max value every " << time_natural_region.front() << " Sec for " << time_max_region.front() << " Sec\x1b[0m" << endl;
}

void Alert_for_voltage(double arr_v[], double arr_t[], int x , double max1)
{
    vector<double> intersection_index, intersection_time,time_max_region,time_natural_region;

    for (int i = 0; i < x; i++)
    {
        if ( (arr_v[i] > max1 && arr_v[i - 1] < max1) || (arr_v[i ] > max1 && arr_v[i + 1] < max1)  )
        {
            intersection_time.push_back(arr_t[i]);
            intersection_index.push_back(i);
        }
    }
    if (!intersection_time.empty())
    {
            for(int j = 0; j < intersection_time.size() - 1; j +=2 )
        {
            time_max_region.push_back(intersection_time.at(j + 1) - intersection_time.at(j));
        }

        for(int k = 1; k < intersection_time.size() - 1; k+=2)
        {
            time_natural_region.push_back(intersection_time.at(k+1) - intersection_time.at(k));
        }
        cout << "\x1b[31mIn the following region from " << intersection_time.front() << " Sec to " << intersection_time.back() << " Sec the voltage is over max value every " << time_natural_region.front() << " Sec for " << time_max_region.front() << " Sec\x1b[0m" << endl;
    }
    else
    cout << "\x1b[32mNo over Load in Voltage!\x1b[37m" << endl;
}
