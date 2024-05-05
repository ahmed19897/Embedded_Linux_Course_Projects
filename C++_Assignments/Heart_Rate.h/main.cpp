#include "HeartRate.h"
#include <iostream>

using namespace std;

int main()
{
    HeartRate HeartRate1("Ahmed","Osama",1,1,1997);
    
    cout<<HeartRate1.getTargetHeartRate(HeartRate1.getMaximumHeartRate(HeartRate1.getAge(2023,HeartRate1.getYear())));

    return 0;
}
