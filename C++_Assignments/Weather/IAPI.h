#include <string>
#include <memory>
#include <iostream>

#ifndef IAPI_H
#define IAPI_H
    class IAPI
    {
    public:
        virtual void SetUrl       (void)=0;
        virtual std::string GetUrl(void)=0;
        virtual void ChangeCity   (std::string&)=0;

    private:
    };
#endif