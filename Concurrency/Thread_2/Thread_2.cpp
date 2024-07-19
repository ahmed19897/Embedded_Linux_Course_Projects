//using yeild for continous threads while using lambda to pass by reference a value to any thread

#include <thread>
#include <iostream>

void func()
{
    while(1)
    {    
        std::cout<<"Thread 2"<<std::endl;
        std::this_thread::yield();
    }
}

int main()
{
    int mynumber=1;

    std::thread thread1
    (
        [&mynumber]()->void
        {
            while(1)
            {
                std::cout<<mynumber<<std::endl;
                std::this_thread::yield();
            }
        }
    );
    std::thread thread2(func);


    
    thread1.join();
    thread2.join();

    return 0;
}