#include "WethearAPI.h"
#include "CurlManager.h"
#include "JsonManager.h"
#include "CacheManager.h"
#include <iostream>
#include <ctime>


int main()
{
    std::shared_ptr< WethearAPI> WAPI=WethearAPI::InitializeandGetInstance();//singleton
    CurlManager MyCurlManager(WAPI);//dependency injection
    JsonManager MyJsonManager;
    CacheManager Cache;
    
    time_t curr_time=time(0);
	tm *tm_local = localtime(&curr_time);
    constexpr int APICallThreshold=1;
    int currenttime=tm_local->tm_hour;
    int lastAPIcallTime=tm_local->tm_hour-APICallThreshold;

    std::string x="Hurgada";
    WAPI->ChangeCity(x);

    for(int i=0;i<2;i++)
    {
        if(currenttime>=lastAPIcallTime+APICallThreshold)//do a new call as long as the last call was 1 hour ago or longer
        {
            //do a new API call
            Cache.WriteCache(MyCurlManager.GetResponse());
            //save the last time we did the call
            tm_local = localtime(&curr_time);
            lastAPIcallTime=tm_local->tm_hour;
        }
        else
        {
            //get the cashed value 
        }
        MyJsonManager.parseandsave(Cache.GetCache());
        std::cout<<MyJsonManager.GetCity()<<" "<<MyJsonManager.GetTemp()<<std::endl;
    }





    return 0;
}
