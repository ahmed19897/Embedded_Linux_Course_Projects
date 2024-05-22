#include <string>
#include <algorithm>
#include <array>
#include<functional>
//create a struct Record with a name and power_level 
//also have two comparison method passed to std::sort the first is by name and the second by power level + create class diagram
//create 3 instances from record and fill them with these values : 
//name: Erin ,  power_level = 100
//name armin, power_level = 80
//name Mikasa, power_level = 120
//name reiner, power_level = 75

class Record
{
    public:
        Record(std::string username,int userPower_Level)
        :name(username),power_level(userPower_Level)
        {
            
        }
    std::string name;
    int power_level;
};
template< class RandomIt,typename t>
void swap(RandomIt &j,RandomIt &i,t temp)
{
    *j=*i;
    *i=temp;

}
template< class RandomIt, class Compare >
void sort( RandomIt first, RandomIt last, Compare comp )
{
    for(RandomIt i=first;i<last;i++)
    {
        for(RandomIt j=i;j<last;j++)
        {
            if(comp(*j,*i))
            {
                swap(j,i,*j);
            }

        }
    }
}
int main()
{
    //initialize a user defined data type array
    std::array <Record,3>  Myarray={Record("Ahmed",2),Record("Mohamed",19),Record("Osama",5)};

    auto CmpareByName       = [](const Record& a, const Record& b)->bool{return a.name > b.name;};
    auto CmpareByPowerLevel = [](const Record& a, const Record& b)->bool{return a.power_level > b.power_level;};

    sort(Myarray.begin(),Myarray.end(),CmpareByPowerLevel);

    return 0;
}