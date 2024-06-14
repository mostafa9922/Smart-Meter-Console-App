#include "main.h"
#include "Data Input.h"
#include "Signal Filtering.h"
#include "Tariff Calculation.h"
#include "Energy Consumption.h"
#include "Period Calculation.h"
#include "power Calculation.h"
#include "Protection Alarms.h"
#include "RMS.h"
#include "Power Factor Calculation.h"
#include "Signal Filtering.h"
#include "Data Logging.h"
#include "Trigeger Alarm.h"
#include "status.h"
// User inter-face for loads --------------------------------------------------------------------------------------------

void showing_l(electrical_properites *data, home_appliances *info)
{

    cout << "Hello to our Smart Meter Application, Please Follow The Instructions" << endl;
            bool a, c , d;
            string selected;
            double cutt_freq = 10000;
            double tsampling = 0.0001;
            double V_max , C_max;
            string n, path;
            for(int i =0; i < num_of_loads; i++)
                {
                      cout << "Please Enter The name of The Load No. " << i + 1  << ":" << endl;
                      getline(cin, n);
                      info[i].set_name(n);
                      c = 1;
                      while (c)
                      {
                          cout << "\x1b[33m"
                               << "please Enter the CSV file Path For The " << info[i].get_name() << ":" << endl
                               << "\x1b[0m";
                          getline(cin, path);
                          ifstream file(path);
                          d = file.is_open();
                          if (d)
                            {
                                  data[i] = read_from_csv(path);
                                  data[i] = Low_pass_filter(data[i].current, data[i].voltage, cutt_freq,tsampling);
                                  data[i] = power_arr_clc(data[i].current_f, data[i].voltage_f, num_of_points);
                                  info[i].set_consumption_time(period_calc(tsampling,num_of_points));
                                  data[i].rms_current = RMS_current_clc(data[i].current_f,num_of_points);
                                  data[i].rms_voltage = RMS_voltage_clc(data[i].voltage_f, num_of_points);
                                  data[i].apparent_power = apparent_power_clc(data[i].rms_current, data[i].rms_voltage);
                                  data[i].active_power = active_power_clc(data[i].power);
                                  data[i].power_factor = power_factor_clc(data[i].active_power, data[i].apparent_power);
                                  data[i].energy = energy(data[i].apparent_power,info[i].get_consumption_time());
                                  data[i].traiff = energyCost(data[i].energy); /* we here we multiply by 30 when use home file*/
                                  info[i].set_status(know_status(data[i].active_power,data[i].apparent_power));
                                  cout << "\x1b[32m Done, The data is processed \x1b[0m" << endl << endl;
                                  c = 0;
                              }
                              else
                              {
                                  cout << "\x1b[31mError, Enter a valid path\x1b[0m" << endl;
                              }
                      }
                }
            a = 1;
            while(a)
            {
                cout << endl;
                cout << "\x1b[36m";
                cout << "Please, Select a Number From The Following As Explained:  " << endl;
                cout << "(0) Properties of the signal" << endl;
                cout << "(1) Current and voltage values of the loads --RMS Value--" << endl;
                cout << "(2) Apparent power and active power and power factor of the loads " << endl;
                cout << "(3) Energy and time consumption and consumption tarrif of the loads " << endl;
                cout << "(4) Save data of the loads to CSV Files  " << endl;
                cout << "(5) Quit the Application " << endl;
                cout << "\x1b[0m";
                getline(cin,selected);
                cout << endl;
                if (selected == "0")
                {
                    for(int i = 0; i < num_of_loads; i++)
                    {
                        cout << "The analysis of the signal of " << info[i].get_name() << endl;
                        Trigger_alarms(data[i].voltage_f,data[i].time,num_of_points);
                        cout << "--- Over Load Analises ---" << endl;
                        Alert_for_current(data[i].current_f, data[i].time,num_of_points, info[i].get_max_current());
                        Alert_for_voltage(data[i].voltage_f, data[i].time, num_of_points, info[i].get_max_voltage());
                        cout << "-----------------------------------" << endl;
                        cout << endl;
                    }
                    cout << "-----------------------------------------------------------------" << endl;
                }
                else if (selected == "1")
                {
                    for(int i =0; i < num_of_loads; i++)
                    {
                        cout << "\x1b[32m";
                        cout << "For the " << info[i].get_name() << " :" << "During regions " << endl;
                        RMS_current_values_clc(data[i].current_f,data[i].time,num_of_points);
                        RMS_voltage_values_clc(data[i].voltage_f,data[i].time,num_of_points);
                        cout << "The RMS current is " << data[i].rms_current << " Amp" << endl;
                        cout << "The RMS Voltage is " << data[i].rms_voltage << " Volt" << endl;
                        cout << "-----------------------------------------------------------------------------" << endl;
                        cout << "\x1b[0m";
                        }
                }
                else if(selected == "2")
                {
                    for(int i =0; i < num_of_loads; i++)
                    {
                        cout << "\x1b[35m";
                        cout << "For the " << info[i].get_name() << " :" << endl;
                        power_show(data[i].power, data[i].time, num_of_points);
                        cout << "The Apparent power is : " << data[i].apparent_power << " VA" << endl;
                        cout << "The Active power is : " << data[i].active_power << " Watt" << endl;
                        cout << "The power factor is : " << data[i].power_factor << endl;
                        cout << "------------------------------------------------------------------------" << endl;
                        cout << "\x1b[0m";
                    }
                }
                else if(selected == "3")
                {
                    for(int i =0; i < num_of_loads; i++)
                    {
                        cout << "\x1b[32m";
                        cout << "For the " << info[i].get_name() << " :" << endl;
                        cout << "Time of consumption is : " << info[i].get_consumption_time() << " sec" << endl;
                        cout << "Consumption is : " << data[i].energy << " Kwh" << endl;
                        cout << "The tarrif of your consumption during the above time is : " << data[i].traiff << " EGP" <<endl;
                        cout << "------------------------------" << endl;
                        cout << "\x1b[0m";
                    }
                }
                else if(selected == "4")
                {
                        csv_writer(data, info);
                }
                else if(selected == "5")
                {
                    cout << "\x1b[33m";
                    cout << "Thank You for using our Application, We Are At Your Service" << endl;
                    cout << "\x1b[0m";
                    a =0;
                }
                else
                {
                    cout << "\x1b[31m";
                    cout << "please enter a valid number " << endl;
                    cout << "\x1b[0m";
                }
            }
}
/*
Files Locations:
    D:\EPE2027\1st Year\Seconed Term\Computer\Project\CSV files\Load1.csv
    D:\EPE2027\1st Year\Seconed Term\Computer\Project\CSV files\Load2.csv
    D:\EPE2027\1st Year\Seconed Term\Computer\Project\CSV files\Load3.csv
    D:\EPE2027\1st Year\Seconed Term\Computer\Project\CSV files\Load4.csv

*/
