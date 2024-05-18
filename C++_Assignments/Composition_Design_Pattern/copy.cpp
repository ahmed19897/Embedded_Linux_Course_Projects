#include "copy.h"
#include <iostream>

bool copy::addelement(pageobject userpageobject)
{
    copylist.push_back(userpageobject);
    return 0;
}
bool copy::addItem(pageobject userpageobject)
{
    std::cout<<"Item Added"<<std::endl;
    return 0;
}
bool copy::deleteItem(pageobject userpageobject)
{
    std::cout<<"Item Removed"<<std::endl;
    return 0;
}
bool copy::removeItem()
{
    std::cout<<"Item Deleted"<<std::endl;
    return 0;
}