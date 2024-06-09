/*1)Weather Forecasting Application
    Description: Create a weather forecasting application that fetches and displays weather data from an online API.
    Technologies: C++17/20, cURL for HTTP requests, JSON for Modern C++ for parsing data, and Qt for the GUI.
*/
/*info about the API call options and format response
https://openweathermap.org/current#geo*/
#include <iostream>
#include <curl/curl.h>
#include <sstream>
#include <jsoncpp/json/json.h>

// Replace with your OpenWeatherMap API key
const std::string API_KEY = "185e30fc60c7e1983bbc533532a81a47";
//Function to handle the response data from curl, the purpose of this funtion is for the app to know the size of the recieved response
size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata) 
{
    std::string* data = static_cast<std::string*>(userdata);
    data->append(static_cast<char*>(ptr), size * nmemb);
    return size * nmemb;
}

int main() {
    CURL *curl;
    CURLcode res;

    // Initialize curl
    curl = curl_easy_init();
    if (curl) {
        // Set the URL with API endpoint and parameters (replace with desired location)
        std::string url = "https://api.openweathermap.org/data/2.5/weather?q=Giza,Egypt&lang=en&units=metric&appid=" +  API_KEY;

//curl_easy_setopt tell the library how to behave with each call basedd on the second parameter
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        // Set output format as JSON
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, curl_slist_append(NULL,"Content-Type: application/json"));
        // Set callback function to handle response data
        std::string response;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION,write_callback );
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        //Now all the behaviour is set correctly we can Perform the HTTP GET request
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }
        // Parse the JSON response
        Json::Reader reader;
        Json::Value root;
        bool success = reader.parse(response, root);

        if (success) 
        {
            // Extract desired weather data (modify as needed)
            std::string city = root["name"].asString();
            double temperature = root["main"]["temp"].asDouble();  //in kelvin
            std::string description = root["weather"][0]["description"].asString();

            // Display the weather information
            std::cout << "City: " << city << std::endl;
            std::cout << "Temperature: " << temperature << "°C" << std::endl;
            std::cout << "Description: " << description << std::endl;
        } 
        else 
        {
            std::cerr << "Failed to parse JSON response" << std::endl;
        }
        // Cleanup curl resources
        curl_easy_cleanup(curl);
    }
    return 0;
}


// g++ -g maincpp -c
// g++ -g -o main main.o -lcurl
// gdb -q main
// start 
// layout asm 
// run