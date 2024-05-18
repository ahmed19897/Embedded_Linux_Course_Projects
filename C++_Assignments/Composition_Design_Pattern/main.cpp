#include "pageobject.h"
#include "page.h"
#include "copy.h"


int main()
{
    page mypage1;
    page mypage2;

    copy thecopy;

    thecopy.addelement(mypage1);
    thecopy.addelement(mypage2);



    return 0;

}