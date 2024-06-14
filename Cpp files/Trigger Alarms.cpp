#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

void Trigger_alarms(double arr_v[], double arr_t[], int x)
{
    vector<double> intersection_index, intersection_time, frequency, time_first_frequency, time_third_frequency, time_seconed_frequency ,first_freq,seconed_freq,third_freq;
    double r1,r2,r3;
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

    // Define a condition for the values you want to move
    auto condition1 = [](int x1) { return x1 < 48; };

    // Copy the elements that satisfy the condition to the destination vector
    copy_if(frequency.begin(), frequency.end(), back_inserter(first_freq), condition1);

    // Define a condition for the values you want to move
    auto condition2 = [](double x2) { return (x2 >= 48 && x2 <= 52); };

    // Copy the elements that satisfy the condition to the destination vector
    copy_if(frequency.begin(), frequency.end(), back_inserter(seconed_freq), condition2);

    // Define a condition for the values you want to move
    auto condition3 = [](double x3) { return x3 > 52; };

    // Copy the elements that satisfy the condition to the destination vector
    copy_if(frequency.begin(), frequency.end(), back_inserter(third_freq), condition3);

    for (int i = 0; i < frequency.size(); i++)
    {
        if (frequency.at(i) < 48)
        {
            time_first_frequency.push_back(intersection_time.at(i));
        }
    }

    for (int i = 0; i < frequency.size(); i++)
    {
        if (frequency.at(i) >= 48 && frequency.at(i) <= 52)
        {
            time_seconed_frequency.push_back(intersection_time.at(i));
        }
    }

    for (int i = 0; i < frequency.size(); i++)
    {
        if (frequency.at(i) > 52)
        {
            time_third_frequency.push_back(intersection_time.at(i));
        }
    }

    for(int i = 0; i < first_freq.size();i++)
    {
        r1 += first_freq.at(i);
    }
    for(int i = 0; i < seconed_freq.size();i++)
    {
        r2 += seconed_freq.at(i);
    }
    for(int i = 0; i < third_freq.size();i++)
    {
        r3 += third_freq.at(i);
    }

    cout << "--- Frequency Analysis ---" << endl;
    if(!time_first_frequency.empty())
    {
        cout << "\x1b[31mThe signal frequency is " << round(r1/first_freq.size()) << " Hz from " << round(time_first_frequency.front()) << " to " << round(time_first_frequency.back()) << " Sec and the periodic time during the brevious region is " << 1/(round(r1/first_freq.size())) << " Sec\x1b[0m"<< endl;
    }
    if(!time_seconed_frequency.empty())
    {
        cout << "\x1b[31mThe signal frequency is " << round(r2/seconed_freq.size()) << " Hz from " << round(time_seconed_frequency.front()) << " to " << round(time_seconed_frequency.back()) << " Sec and the periodic time during the brevious region is " << 1/(round(r2/seconed_freq.size())) << " Sec\x1b[0m" << endl;
    }
    if(!time_third_frequency.empty())
    {
        cout << "\x1b[31mThe signal frequency is " <<  round(r3/third_freq.size())  << " Hz from " << round(time_third_frequency.front()) << " to " << round(time_third_frequency.back()) << " Sec and the periodic time during the brevious region is " << 1/(round(r3/third_freq.size())) << " Sec\x1b[0m" << endl;
    }
    cout << "--------------------------------------" << endl;

}
