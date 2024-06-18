#include "Engine.h"
#include <memory>

class V8Engine : public Engine
{
    void Start() override ;
    void Stop() override ;
};
std::unique_ptr<Engine> MakeV8Engine();