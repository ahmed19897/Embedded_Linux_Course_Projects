#include "WethearAPI.h"
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
