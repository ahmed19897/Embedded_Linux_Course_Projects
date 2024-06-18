#include <memory>
#include <iostream>

int main()
{
    // std::unique_ptr<int>p1(new int(5));
    // std::cout<<*p1<<std::endl;

    auto p1=std::make_unique<int>(5);
    auto p2=std::move(p1);
    std::cout<<*p2<<std::endl;

    return 0;

}