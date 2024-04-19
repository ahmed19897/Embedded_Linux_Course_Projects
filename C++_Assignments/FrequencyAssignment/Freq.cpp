#include <iostream>
#include <iomanip>
#include <cmath>
#include <array>
#include <algorithm>
void swap(int &value1,int &value2);
int main()
{
//1 implmentation
//this implmentation depends on us knowing the maximum value the user can input
    // constexpr unsigned int Size=13;
    // std::array<int,Size>sales={ 3,3,5,8,9,8,9,10,12,10,11,12,10};
    // int i=0;
    // std::array<int,Size>Category={};
    //     for(int &itemss:sales)
    //     {   
    //         Category[itemss]++;
    //     }
    //     for(auto const items:Category)
    //     {
    //         std::cout<<i<<" ";
    //         std::cout<<items<<std::endl;
    //         i++;
    //     }

//2 implmentation
//a little more computationally expensive but doesn't have the restriction of the first implmen.
//     constexpr unsigned int Size=13;
//     std::array<int,Size>sales={ 3,3,5,8,9,8,9,10,12,10,11,12,10};
//     int begininterval{0},endinterval{0},freq{0};
//     unsigned int salessize=sales.size();
// //order the array
//     for(int i=0;i<salessize;i++)
//     {
//         for(int j=0;j<salessize;j++)
//         {
//             if(sales[j]>sales[j+1])
//             {
//                 swap(sales[j],sales[j+1]);
//             }
//         }
//     }
// //extract the interval where the same value begin and end
//     for(int i=0;i<salessize;i++)
//     {
//         if(i==0)
//         {
//             begininterval=i;
//             endinterval=i;
//         }
//         else
//         {
//             if(sales[i]!=sales[i+1])
//             {
//                 endinterval=i;
//                 //the difference between the beg and end is the freq
//                 freq=(endinterval-begininterval)+1;
//                 begininterval=i+1;
//                 std::cout<<sales[i]<<" freq-> "<<freq<<std::endl;
//             }
            
//         }
//   }
    return 0;
}


void swap(int &value1,int &value2)
{
    int temp=value1;
    value1=value2;
    value2=temp;
}