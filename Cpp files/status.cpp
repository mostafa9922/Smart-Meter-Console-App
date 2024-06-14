int know_status(double x , double y)
// X is the active power
// Y is the average power
{
// ON
if ( x > y)
    return 1;
// OFF
if (x == 0)
    return 0;
//FAULT
if (x <= y)
    return 2;
}

