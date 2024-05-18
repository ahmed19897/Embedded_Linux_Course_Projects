#include <vector>
#include "pageobject.h"
#ifndef COPY_H
#define COPY_H

class copy:public pageobject
{
private:
    std::vector<pageobject>copylist;
public:
    virtual bool addItem(pageobject userpageobject);
    virtual bool removeItem();
    virtual bool deleteItem(pageobject userpageobject);
    virtual bool addelement(pageobject userpageobject);
};

#endif