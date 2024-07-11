#ifndef MOCKCALC_H
#define MOCKCALC_H

    #include "calculator.hpp"
    #include "gmock/gmock.h"

    class calculatormock:public calculator
    {
        public:
            MOCK_METHOD(int,add,(int a,int b),(override));
            MOCK_METHOD(int,sub,(int a,int b),(override));
            MOCK_METHOD(int,mul,(int a,int b),(override));
            MOCK_METHOD(int,div,(int a,int b),(override));
                  
    };




#endif