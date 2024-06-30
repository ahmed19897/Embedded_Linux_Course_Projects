#include <jsoncpp/json/json.h>
#include "CurlManager.h"
#ifndef JsonManager_H
#define JsonManager_H
class JsonManager
{
private:
    Json::Reader reader     ;
    Json::Value root        ;
    bool success            ;
    std::string city        ;
    double temperature      ;
    std::string description ;

public:
    JsonManager(){};
    ~JsonManager(){};

    void parseandsave(std::string response)
    {
        success = reader.parse(response, root);
        if (success)
        {
            // Extract desired weather data (modify as needed)
            city        = root["name"].asString();
            temperature = root["main"]["temp"].asDouble();  //in kelvin
            description = root["weather"][0]["description"].asString();
        }
        else
        {
            std::cerr << "Failed to parse JSON response" << std::endl;
        }
    }
    std::string GetCity(void)const
    {
        return city;
    }
    double GetTemp(void)const
    {
        return temperature;
    }
    std::string GetDescription(void)const
    {
        return description;
    }
};

#endif




