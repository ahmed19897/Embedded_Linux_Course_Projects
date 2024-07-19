//first multithreading usign lambda function , random engine and randomint to generate numbers for display and finally get the thread id for more info 
#include <thread>
#include <iostream>
#include <random>

std::default_random_engine engine(static_cast<unsigned int>(time(0)));
std::uniform_int_distribution<unsigned int> randomInt(10,40);

std::thread::id t1_id;
std::thread::id t2_id;

int currentemp=0;

int main()
{
    //unsigned int n = std::thread::hardware_concurrency();
    //std::cout << n << " concurrent threads are supported.\n";

    auto LCD_Display=[]()->void
    {
        while(1)
        {
            std::cout<<"From ID:"<<t1_id<<"\nCurren Temp= "<<currentemp<<'\n'<<std::endl;
            std::this_thread::sleep_for (std::chrono::seconds(1));
        }
    };
    auto Read_Temp=[]()->void
    {
        while(1)
        {
            std::cout<<"From ID:"<<t2_id<<'\n'<<std::endl;
            currentemp=randomInt(engine);
            std::this_thread::sleep_for (std::chrono::milliseconds(100));
        }
    };

    std::thread thread1(Read_Temp);
    t1_id= thread1.get_id();
    std::thread thread2(LCD_Display);
    t2_id = thread2.get_id();
    
    thread1.join();
    thread2.join();

    return 0;
}