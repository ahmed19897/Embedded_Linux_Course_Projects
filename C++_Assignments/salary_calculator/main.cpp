#include "Employee.h"
#include "salary_calculator.h"
#include <iostream>
using namespace std;

int main()
{
    Employee Employee1("Ahmed","Osama",123);
    Employee Employee2("Mohamed","Alaa",321);

    // cout<<Employee1.getMonthlySalary()*12<<" "<<Employee2.getMonthlySalary()*12<<'\n'<<endl;

    // Employee1.setMonthlySalary((Employee1.getMonthlySalary()*0.1)+Employee1.getMonthlySalary());
    // Employee2.setMonthlySalary((Employee2.getMonthlySalary()*0.1)+Employee2.getMonthlySalary());

    // cout<<Employee1.getMonthlySalary()*12<<" "<<Employee2.getMonthlySalary()*12;

    Salary_Calculate(Employee1);

    return 0;
}

