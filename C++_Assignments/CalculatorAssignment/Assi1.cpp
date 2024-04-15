#include<iostream>
#include<cmath>

//use structs
//use doxygen
//use input error handling
//use error handling
void CheckUserInput(std::istream & input);
namespace Calculator
{
    int Add(int &a,int &b)
    {
        return a+b;
    }
    int Sub(int &a,int &b)
    {
        return a-b;
    }
    int Multi(int &a,int &b)
    {
        return a*b;
    }
    int Divide(int &a,int &b)
    {
        if(b==0)
        {
            std::cerr<<"invalid division"<<std::endl;
            a=1.0;
            b=1.0;
        }
        return a/b;
    }
    int Remainder(int &a,int &b)
    {
        return a%b;
    }
    int Power(int &a,int &b)
    {
        return pow(a,b);
    }
}


int main()
{
    int operand1=0.0;
    int operand2=1.0;
    char useroperator=' ';
    int result=0.0;
    bool usercontinue=true;


    while(usercontinue)
    {
        std::cout<<"please enter the first operand: ";
        CheckUserInput(std::cin>>operand1);
        

        std::cout<<"please enter opeartors :+,-,*,/,%: ";
        CheckUserInput(std::cin>>useroperator);

        std::cout<<"please enter the second operand: ";
        CheckUserInput(std::cin>>operand2);


        if(useroperator=='+')
        {
            result=Calculator::Add(operand1,operand2);
        }
        else if(useroperator=='-')
        {
            result=Calculator::Sub(operand1,operand2);
        }
        else if(useroperator=='*')
        {
            result=Calculator::Multi(operand1,operand2);
        }
        else if(useroperator=='/')
        {
            result=Calculator::Divide(operand1,operand2);
        }   
        else if(useroperator=='%')
        {
            result=Calculator::Remainder(operand1,operand2);
        }
        else if(useroperator=='^')
        {
            result=Calculator::Power(operand1,operand2);
        }
        else
        {
            std::cerr<<"illegal operator"<<std::endl;
        }

        std::cout<<"The result is->"<<result<<std::endl;
        std::cout<<"enter 1 to Continue /0 to abort: ";
        std::cin>>usercontinue;
        std::cout<<std::endl;
        system("clear");

    }




    return 0;
}

void CheckUserInput(std::istream & input)
{
    if(input.fail()==1)
    {
        std::cerr<<"Bad Input"<<std::endl;
        exit(EXIT_FAILURE);;
    }
}