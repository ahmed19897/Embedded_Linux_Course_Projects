#include <string>

class HeartRate
{

    public:
            HeartRate(std::string firstname,std::string lastname,int month,int day,int year);
            void setFirstName(std::string firstname);
            void setLastName(std::string lastname);
            void setMonthlySalary(int monthlysalary);
            void setMonth(int month);
            void setDay(int day);
            void setYear(int year);
            std::string getFirstName()const;
            std::string getLastName()const;
            int getMonth()const;
            int getDay()const;
            int getYear()const;
            void displayDate()const;
            int getAge(int Currentyear,int Customeryear)const;
            int getMaximumHeartRate(int Age)const;
            int getTargetHeartRate(int MaximumHeartRate)const;

    private:
            std::string FirstName;
            std::string LastName;
            int Month;
            int Day;
            int Year;

};