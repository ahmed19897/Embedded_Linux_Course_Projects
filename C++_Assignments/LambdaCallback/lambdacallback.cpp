//callback function using lambda
#include<iostream>
#include<iomanip>
#include<functional>
bool callback(void);
void func(std::function<bool(void)>argu1);
int main()
{
    auto k=[]()->void{
                std::cout<<"Hello"<<std::endl;
            };
    k();
    func(callback);

    return 0;
}

void func(std::function<bool(void)>argu1)
{
   auto result=[&argu1](bool &response)
   {
    response = argu1();
    return true;
   };
   bool param=false;
   result(param);
}

bool callback(void)
{
    return true;
}