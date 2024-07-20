#include <string>
#include <memory>
#include <iostream>
#include "iapi.h"

#ifndef WETHEARAPI_H
#define WETHEARAPI_H
class WethearAPI :public IAPI
{
public:
    WethearAPI(/* args */        ) ;
    WethearAPI                 (const WethearAPI&) = delete;
    const WethearAPI& operator=(const WethearAPI&)       = delete;


    static std::shared_ptr<WethearAPI> InitializeandGetInstance(void);
    void SetUrl(void) ;
    std::string GetUrl(void) ;
    void ChangeCity(std::string&) ;
    void ChangeUnits(int newunit) ;
    void ChangeLang(int newlang) ;
private:
    static std::shared_ptr<WethearAPI> instance;

    std::string url;
    const std::string API_KEY = "185e30fc60c7e1983bbc533532a81a47";
};
#endif
