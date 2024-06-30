#include <string>
#include <memory>
#include <iostream>
#include "IAPI.h"

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
    private:
        static std::shared_ptr<WethearAPI> instance;

        std::string url;
        const std::string API_KEY = "185e30fc60c7e1983bbc533532a81a47";
    };
#endif


//referening the static class wide definition here made "instanec" loaded into .bss section
//without this referencing "instance" got loaded into UND section then we got error about relocating
std::shared_ptr<WethearAPI> WethearAPI::instance;


WethearAPI::WethearAPI()
{         
    SetUrl();
}     


std::shared_ptr<WethearAPI> WethearAPI::InitializeandGetInstance(void)
{
    if(instance == nullptr) 
    {
        instance  = std::make_shared<WethearAPI>();
        std::cout << "InitializeandGetInstance(): First instance\n";
    }
    else 
    {
        std::cout << "InitializeandGetInstance(): previous instance\n";
    }
    return instance;
}
void WethearAPI::SetUrl()
{
    url ="https://api.openweathermap.org/data/2.5/weather?q=Giza,Egypt&lang=en&units=metric&appid=" +  API_KEY; 
}
std::string WethearAPI::GetUrl(void)
{
    return  url;
}
void WethearAPI::ChangeCity(std::string&newcity)
{
    int indexstart=url.find("q=");
    indexstart=indexstart+2;
    int indexend=url.find(",");
    url.replace(indexstart,(indexend-indexstart),newcity);
}