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
#include"pageobject.h"

#ifndef PAGE_H
#define PAGE_H

class page:public pageobject 
{
private:
public:
    virtual bool addItem(pageobject userpageobject);
    virtual bool removeItem();
    virtual bool deleteItem(pageobject userpageobject);
};




#endif