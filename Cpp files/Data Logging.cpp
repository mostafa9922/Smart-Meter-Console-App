#include "main.h"
void csv_writer(electrical_properites arr1[], home_appliances arr2[])
{
    string path;
    bool k ;
    for (int i = 0; i < num_of_loads; i++)
    {
        k  = 1;
        while(k)
        {
            cout << "please, Enter The name of CSV file of the load " << arr2[i].get_name() << " will created like this : ---- load.csv ----  " << endl;
            getline(cin,path);
            ofstream outfile1(path);
            if (!outfile1.is_open())
                {
                    cout << "\x1b[31m Failed to create a file for writing! , Please enter a valid name \x1b[0m" << endl;
                }
            else
            {
                outfile1 << "Time" << ',' << "Filtered Current" << ',' << "Filtered voltage" << ',' << "Power" << '\n';
                for (int j = 0; j < num_of_points; j++)
                    {
                        outfile1 << arr1[i].time[j] << ',' << arr1[i].current_f[j] << ',' << arr1[i].voltage_f[j] << ',' << arr1[i].power[j] << '\n';
                    }
                outfile1.close();
                cout << "\x1b[32m The file is created \x1b[0m" << endl;
                k = 0;
            }
        }
    }
}
