#include "WethearAPI.h"
#include "CurlManager.h"
#include "JsonManager.h"
#include <iostream>

int main()
{
    std::shared_ptr< WethearAPI> WAPI=WethearAPI::InitializeandGetInstance();//singleton
    CurlManager MyCurlManager(WAPI);//dependency injection
    JsonManager MyJsonManager;
    
    std::string x="Hurgada";
    WAPI->ChangeCity(x);

    MyJsonManager.parseandsave(MyCurlManager.GetResponse());
    std::cout<<MyJsonManager.GetCity()<<" "<<MyJsonManager.GetTemp()<<std::endl;

    

    return 0;
}