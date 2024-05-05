#include "pointclass.h"


int main()
{
    pointclass mypoint;

    float x=-2; 
    float y=2;
    pointclass mypoint2(x,y);
    mypoint2.ConvertToPolar();

    float theta=40.0;
    float raduis=3;
    pointclass mypoint3(theta,raduis);
    mypoint3.ConvertToCartesian();
    

    return 0;
}