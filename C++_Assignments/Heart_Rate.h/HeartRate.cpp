#include "HeartRate.h"
#include <iostream>
using namespace std;



HeartRate::HeartRate(std::string firstname,std::string lastname,int month,int day,int year)
    :FirstName(firstname),LastName(lastname),Year(year)
{
    if (month>0 && month<=12)
    {
        Month=month;
    }
    else
    {
        Month=1;
        cerr<<"Month input is invalid";
    }

    if (day>0 && day<=31)
    {
        Day=day;
    }
    else
    {
        day=1;
        cerr<<"Day input is invalid";
    }



}





void HeartRate::setFirstName(string firstname)
{
    FirstName=firstname;
}
void HeartRate::setLastName(string lastname)
{
    LastName=lastname;
}

void HeartRate::setMonth(int month)
{
    if (month>0 && month<=12)
    {
        Month=month;
    }
    else
        Month=1;
}
void HeartRate::setDay(int day)
{

    if (day>0 && day<=31)
    {
        Day=day;
    }
    else
    {
        day=1;
        cerr<<"Day input is invalid";
    }
}
void HeartRate::setYear(int year)
{
    Year=year;
}




string HeartRate::getFirstName()const
{
    return FirstName;
}
string HeartRate::getLastName()const
{
    return LastName;
}
int HeartRate::getMonth()const
{
    return Month;
}
int HeartRate::getDay()const
{
    return Day;
}
int HeartRate::getYear()const
{
    return Year;
}





void HeartRate::displayDate()const
{
    cout<<getMonth()<<'/'<<getDay()<<'/'<<getYear()<<endl;
}
int HeartRate::getAge(int Currentyear,int Customeryear)const
{

    return Currentyear-Customeryear;

}
int HeartRate::getMaximumHeartRate(int Age)const
{
    return 220-Age;
}
int HeartRate::getTargetHeartRate(int MaximumHeartRate)const
{
    cout<<"Your Target Heart Rate is: "<<0.5*MaximumHeartRate<<" to "<<0.85*MaximumHeartRate<<endl;
}