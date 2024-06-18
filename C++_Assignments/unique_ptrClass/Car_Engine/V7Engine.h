#include "Engine.h"
#include <iostream>

class V7Engine : public Engine
{
    void Start() override
    {
        std::cout << "Start V7 Engine \n";
    }
    void Stop() override 
    {
         std::cout << "Start V7 Engine \n";
    }
};