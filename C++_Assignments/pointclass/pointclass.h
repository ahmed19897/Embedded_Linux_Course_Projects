#include <cstdint>
#ifndef POINTCLASS_H
#define POINTCLASS_H
    class pointclass
    {
        private:
            float x_or_raduis;
            float y_or_theta;
            float CalculateTheta(void);
        public:
            pointclass(void);//default values constructor
            pointclass(float,float);//polar/cartesian constructor
            
            void Setx_or_raduis    (float);
            void Sety_or_theta    (float);

            
            float   Getx_or_raduis    (void)const;
            float   Gety_or_theta    (void)const;

            bool ConvertToCartesian(void);
            bool ConvertToPolar(void);
            
            
            ~pointclass();
    };
#endif