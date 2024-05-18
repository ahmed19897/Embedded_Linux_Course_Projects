/*
1) Create PageObject as a component for a composite pattern
includes: addItem, removeItem and deleteItem
Note: PageObject is a base class not an abstract class

2) Inherit Page from PageObject

3) Create Composite class Copy (combine inheritance and composition)
contains list of PageObject also inherits from PageObject

please create a complete class diagram (and be able to present it)
use tools such as UMLet or draw.io
*/
#include <string>
#ifndef PAGE_OBJECT_H
#define PAGE_OBJECT_H

class pageobject
{
private:
public:
    virtual bool addItem(pageobject userpageobject)
    {
       return 0;
    }
    virtual bool removeItem()
    {
        return 0;
    }
    virtual bool deleteItem(pageobject userpageobject)
    {
        return 0;
    }
};

#endif