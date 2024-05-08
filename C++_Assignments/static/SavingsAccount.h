#include <iostream>
#include <iostream>
#include <iomanip>
#include <stdexcept>
using  namespace std;

#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H


    class SavingsAccount
    {
    private:
        static float annualfloaterest;//class wide definition
        float SavingsBalance;
    public:
        SavingsAccount(float=1.0);
        ~SavingsAccount();
        void calculateMonthlyfloaterest();
        void DisplayBalance()const;
        static void DisplayInterest();//accesses through class name then ""::" 
        void SetBalance(float);
        static void SetAnnualRate(float);
        void ResetBalance();
    };

    SavingsAccount::SavingsAccount(float SB)
    {
        SetBalance(SB);
    }

    SavingsAccount::~SavingsAccount()
    {
    }

    void SavingsAccount::calculateMonthlyfloaterest()
    {   
        cout<<"The monthly Rate is :"<<(SavingsBalance*(annualfloaterest/100))/12<<endl;
        SavingsBalance+=(SavingsBalance*(annualfloaterest/100))/12;
    }
    void SavingsAccount::DisplayBalance()const
    {
        cout<<"Account Balance is:"<<SavingsBalance<<endl;
    }

    void SavingsAccount::SetBalance(float SB)
    {

            if(SB>0)
        {
            SavingsBalance=SB;
        }
        else
            throw invalid_argument("Account Starting number must be bigger than 0");

    }
    float SavingsAccount::annualfloaterest=1.0;
    void SavingsAccount::SetAnnualRate(float AI)
    {
        if(AI>0.0)
        {
            annualfloaterest=AI;
        }
        else
            throw invalid_argument("Annual Interest number must be bigger than 0");
    }

    void SavingsAccount::DisplayInterest()
    {
        cout<<"Interest Rate is:"<<annualfloaterest<<endl;
    }

    void SavingsAccount::ResetBalance()
    {
        SavingsBalance=0.0;
    }


#endif