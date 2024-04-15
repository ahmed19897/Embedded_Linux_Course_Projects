#include<iostream>
void ConvergeToWeekday(const int & targetday);
void CheckUserInput(std::istream & input);
int main()
{
    int inttoday=0;
    int inttargetday=0;
    int desiredday=0;
    bool usercontinue=true;

    while(usercontinue)
    {
        inttoday=0;
        inttargetday=0;
        desiredday=0;

        while(inttoday<=0 || inttoday>=8)
        {
            system("clear");
            std::cout<<"1-Monday\n2-Tuesday\n3-Wednesday\n4-Thursday\n5-Friday\n6-Saturday\n7-Sunday"<<std::endl;
            std::cout<<"please enter Today weekday"<<std::endl;
            CheckUserInput (std::cin>>inttoday);
        }

        std::cout<<"please enter target day number"<<std::endl;
        CheckUserInput (std::cin>>inttargetday);

        desiredday=((inttoday+inttargetday)%7);
        ConvergeToWeekday(desiredday);
        std::cout<<"continue->1\nabort->0"<<std::endl;
        std::cin>>usercontinue;
        system("clear");
    }


    return 0;
}













void ConvergeToWeekday( const int & targetday)
{
    switch(targetday)
    {
        case 1:
            std::cout<<"Monday"<<std::endl;
        break;

        case 2:
            std::cout<<"Tuesday"<<std::endl;
        break;
    
        case 3:
            std::cout<<"Wednesday"<<std::endl;
        break;

        case 4:
            std::cout<<"Thurday"<<std::endl;
        break;

        case 5:
            std::cout<<"Friday"<<std::endl;
        break;

        case 6:
            std::cout<<"Saturday"<<std::endl;
        break;

        case 7:
            std::cout<<"Sunday"<<std::endl;
        break;

        default:
            std::cout<<"invalid day"<<std::endl;
        break;
    }
}
void CheckUserInput(std::istream & input)
{
    if(input.fail()==1)
    {
        std::cerr<<"Bad Input"<<std::endl;
        exit(EXIT_FAILURE);;
    }
}