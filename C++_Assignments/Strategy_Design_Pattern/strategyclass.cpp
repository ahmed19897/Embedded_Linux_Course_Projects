//create Istrategy abstract class inherit
//two classes StrategyBMW and StrategyMiniCooper
//and the context is Vehicle and use Vehicle with two instances in main + create class diagram
#include <iostream>


/// @brief //////////////////////////////////////////////////////////////////////////////////////////////////
class Istrategy
{
private:
    /* data */
public:
    virtual void DisplayStrategy()=0;
};
/// @brief //////////////////////////////////////////////////////////////////////////////////////////////////
class StrategyBMW:public Istrategy
{
private:
    /* data */
public:
    virtual void DisplayStrategy()
    {
        std::cout<<"BMW Strategy !"<<std::endl;
    }
};
/// @brief //////////////////////////////////////////////////////////////////////////////////////////////////
class StrategyMiniCooper:public Istrategy
{
private:
    /* data */
public:
    virtual void DisplayStrategy()
    {
        std::cout<<"MiniCooper Strategy !"<<std::endl;
    }
};
/// @brief //////////////////////////////////////////////////////////////////////////////////////////////////
struct Vehicle
{
    Vehicle(Istrategy *UserStrategy)
    :MyStrategy(UserStrategy)
    {
    }
    void CallStrategy()
    {
        MyStrategy->DisplayStrategy();
    }
    Istrategy *MyStrategy;
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
    StrategyBMW BMW;
    StrategyMiniCooper MINICOOPER;

    Vehicle MyVehicle(&BMW);
    MyVehicle.CallStrategy();

    MyVehicle=&MINICOOPER;
    MyVehicle.CallStrategy();

    return 0;

}