/*create template functions for max and swap and apply on fundamental data types such as 
int and double also apply on user defined data types (create a Person class and overload 
the necessary operators)*/
#include <iostream>
#include <string>
template<typename t>
t max(t &userinput1,t &userinput2)
{
   if(userinput1>=userinput2)
   {
    return userinput1;
   }
   else
   {
    return userinput2;
   }
}
template<typename t>
void swap(t &userinput1,t &userinput2)
{
    t temp=userinput1;
    userinput1=userinput2;
    userinput2=temp;
}
class person
{
private:
    std::string name;
    int age;
public:
    person(std::string name,int age)
    :name(name),age(age)
    {

    }
    const person &operator=(const person & userinput)
    {
        this->name=userinput.name;
        this->age=userinput.age;

        return *this;
    }
};



int main()
{
    int x{4};
    int y{5};
    int z{6};

    std::cout<<(max(y,x))<<std::endl;
    std::cout<<(max(x,y))<<std::endl;

    std::cout<<"before swap "<<"x:"<<x<<" Y:"<<y<<std::endl;
    swap(x,y);
    std::cout<<"After swap "<<"x:"<<x<<" Y:"<<y<<std::endl;


    person person1("Ahmed",22);
    person person2("Osama",45);

    person1=person2;



    return 0;
}