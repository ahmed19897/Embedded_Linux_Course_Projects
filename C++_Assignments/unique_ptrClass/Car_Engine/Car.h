#pragma once
#include "Engine.h"
#include <memory>

class Car
{
public:
    Car(std::unique_ptr<Engine>&& engine);

    void Drive();
    void Stop();
private:
    std::unique_ptr<Engine> m_engine; 
};