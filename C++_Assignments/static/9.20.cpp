#include "SavingsAccount.h"

//static var in func -> gets  initialized once
//static func in file -> seen only in the file
//static data in class -> class wide defined
//static method in class -> gets accesees by class name then scope resolution
int main()
{
    SavingsAccount Saver1,Saver2;

    SavingsAccount::SetAnnualRate(3.0);
    Saver1.SetBalance(2000);
    Saver2.SetBalance(3000);
    Saver1.calculateMonthlyfloaterest();
    Saver2.calculateMonthlyfloaterest();
    Saver1.DisplayBalance();
    Saver2.DisplayBalance();
    Saver1.ResetBalance();
    Saver2.ResetBalance();

    cout<<endl;

    SavingsAccount::SetAnnualRate(4.0);
    Saver1.SetBalance(2000);
    Saver2.SetBalance(3000);
    Saver1.calculateMonthlyfloaterest();
    Saver2.calculateMonthlyfloaterest();
    Saver1.DisplayBalance();
    Saver2.DisplayBalance();
    Saver1.ResetBalance();
    Saver2.ResetBalance();
}