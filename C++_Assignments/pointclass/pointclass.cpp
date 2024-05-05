#include "pointclass.h"
#include <iostream>
#include <cmath>
/*Constructor's implmentation*/
    pointclass::pointclass(void)
    :x_or_raduis(0),y_or_theta(0)
    {
    }
    pointclass::pointclass(float userx_or_raduis,float usery_or_theta)
    :x_or_raduis(userx_or_raduis),y_or_theta(usery_or_theta)
    {  
    }
/*Constructor's implmentation*/

/*Destructor's implmentation*/
    pointclass::~pointclass()
    {
    }
/*Destructor's implmentation*/

/*setters implmentation*/
    void pointclass::Setx_or_raduis(float userx_or_raduis)
    {
        if(userx_or_raduis>=0)
        {
            x_or_raduis=userx_or_raduis;
        }
        else
        {
            std::cerr<<"radius value must be bigger than or equal 0"<<std::endl;
        }
    }
    void pointclass::Sety_or_theta    (float usery_or_theta)
    {
        if(usery_or_theta>=0.0)
        {
            y_or_theta=usery_or_theta;
        }
        else
        {
            std::cerr<<"theta value must be bigger than or equal 0.0"<<std::endl;
        } 
    }
/*setters implmentation*/

/*getters implmentation*/
    float   pointclass::Getx_or_raduis    (void)const
    {
        return x_or_raduis;
    }
    float   pointclass::Gety_or_theta    (void)const
    {
        return y_or_theta;
    }
/*getters implmentation*/


bool pointclass::ConvertToCartesian(void)
{
    
    x_or_raduis=x_or_raduis*cos(y_or_theta);
    y_or_theta=x_or_raduis*sin(y_or_theta);
    std::cout<<"Current Mode is Cartesian x:"<<Getx_or_raduis()<<" y:"<<Gety_or_theta()<<std::endl;
    return 0;
}
bool pointclass::ConvertToPolar(void)
{
    y_or_theta=CalculateTheta();
    x_or_raduis=sqrt(pow(x_or_raduis,2)+pow(y_or_theta,2));
    std::cout<<"Current Mode  is Polar raduis:"<<Getx_or_raduis()<<" theta:"<<Gety_or_theta()<<std::endl;
    return 0;
}


float pointclass::CalculateTheta(void)
{
    constexpr float pi=3.1415;
    if(x_or_raduis>0.0 && y_or_theta>0.0)//quad 1
    {
        return atan(y_or_theta/x_or_raduis);
    }
    else if(x_or_raduis<0.0 && y_or_theta>0.0)//quad 2
    {
        return atan(y_or_theta/x_or_raduis)+pi;
    }
    else if(x_or_raduis<0.0 && y_or_theta<0.0)//quad 3
    {
        return atan(y_or_theta/x_or_raduis)-pi;
    }
    else//quad 4
    {
        return atan(y_or_theta/x_or_raduis)+(2*pi);
    }
}