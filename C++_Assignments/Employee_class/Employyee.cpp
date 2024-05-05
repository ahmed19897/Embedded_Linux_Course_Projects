#include "Employee.h"

using namespace std;

Employee::Employee (std::string firstname,std::string lastname,int monthlysalary)
    :FirstName(firstname),LastName(lastname),MonthlySalary(monthlysalary)
{

}


void Employee::setFirstName(string firstname)
{
    FirstName=firstname;
}
void Employee::setLastName(string lastname)
{
    LastName=lastname;
}
void Employee::setMonthlySalary(int monthlysalary)
{
    if (monthlysalary<0)
    {
        MonthlySalary=0;
    }
    else
    MonthlySalary=monthlysalary;
}
string Employee::getFirstName()const
{
    return FirstName;
}
string Employee::getLastName()const
{
    return LastName;
}
int Employee::getMonthlySalary()const
{
    return MonthlySalary;
}