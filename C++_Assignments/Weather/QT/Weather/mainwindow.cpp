#include <iostream>
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <curl/curl.h>
#include <sstream>
#include <jsoncpp/json/json.h>
// Replace with your OpenWeatherMap API key
const std::string API_KEY = "185e30fc60c7e1983bbc533532a81a47";
size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata)
{
    std::string* data = static_cast<std::string*>(userdata);
    data->append(static_cast<char*>(ptr), size * nmemb);
    return size * nmemb;
}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_WeatherButton_clicked()
{
    //ui->GetandPrintWeather();





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
            const QString cityQ=QString::fromStdString(city);
            ui->textEdit->setPlainText(cityQ);

            std::string temperatures=std::to_string(temperature);
            const QString temperatureQ=QString::fromStdString(temperatures);
            ui->textEdit2->setPlainText(temperatureQ);


            const QString descriptionQ=QString::fromStdString(description);
            ui->textEdit3->setPlainText(descriptionQ);

            // std::cout << "City: " << city << std::endl;
            // std::cout << "Temperature: " << temperature << "°C" << std::endl;
            // std::cout << "Description: " << description << std::endl;
        }
        else
        {
            std::cerr << "Failed to parse JSON response" << std::endl;
        }
        // Cleanup curl resources
        curl_easy_cleanup(curl);
    }


}




