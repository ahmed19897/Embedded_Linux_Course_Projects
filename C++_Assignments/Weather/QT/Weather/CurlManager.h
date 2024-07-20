#include <iostream>
#include <memory>
#include <curl/curl.h>
#include <string>
#include "iapi.h"

#ifndef CURLMANAGER_H
#define CURLMANAGER_H
class CurlManager
{
public:
    CurlManager( )
    {
        curl = curl_easy_init();
    }
    ~CurlManager()
    {
        curl_easy_cleanup(curl);
    }
    void SetBehaviour(void)
    {
        //curl_easy_setopt tell the library how to behave with each call basedd on the second parameter
        curl_easy_setopt(curl, CURLOPT_URL, (APIObject->GetUrl()).c_str());
        // Set output format as JSON
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, curl_slist_append(NULL,"Content-Type: application/json"));
        // Set callback function to handle response data
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION,write_callback );
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    }
    void PerformHttpRequest(void)
    {
        res = curl_easy_perform(curl);
        if (res != CURLE_OK)
        {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }
        else
        {
            //success
        }
    }
    std::string GetResponse(void)
    {
        response="";
        SetBehaviour();
        PerformHttpRequest();
        return response;
    }
    void SetAPIObject(std::shared_ptr<IAPI> APIObjectReference)
    {
        APIObject=APIObjectReference;
    }
    void ChangeCity(std::string&newcity)
    {
        APIObject->ChangeCity(newcity);
    }
    void ChangeUnits(int newunit)
    {
        APIObject->ChangeUnits(newunit);
    }

private:
    std::shared_ptr< IAPI>  APIObject;
    //calculate the size of the http response
    static size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata)
    {
        std::string* data = static_cast<std::string*>(userdata);//convert user data to string
        data->append(static_cast<char*>(ptr), size * nmemb);//append the size of the response
        return size * nmemb;//return the response size
    }
    CURL *curl;
    CURLcode res;
    std::string response;
};
#endif
