#include <string>


class Employee
{

    public:
            explicit Employee (std::string firstname,std::string lastname,int monthlysalary);
            void setFirstName(std::string firstname);
            void setLastName(std::string lastname);
            void setMonthlySalary(int monthlysalary);
            std::string getFirstName()const;
            std::string getLastName()const;
            int getMonthlySalary()const;



    private:
            std::string FirstName;
            std::string LastName;
            int MonthlySalary;

};