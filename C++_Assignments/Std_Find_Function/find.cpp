 #include <array>
 #include <iostream>
 template<class InputIterator, class T>
  InputIterator find (InputIterator first, InputIterator last, const T& val)
  {
    //while we havn't reached the last element
    while(first!=last)
    {
        if(*first==val)
        {
            //value found so we need to return
            return first;
        }
        else
        {
            //value doesn't match so we need to go to next element
            first++;
        }
    }
    //no value found
    return last;
  }

  int main()
  {
    std::array<int,3>myarray{1,2,3};
    int targetnumber=0;

    std::cout<<"Please enter a number to search: ";
    std::cin>>targetnumber;
    std::cout<<'\n';

    if(targetnumber==*(find(myarray.begin(),myarray.end(),targetnumber)))
    {
        std::cout<<"Found"<<std::endl;
    }
    else
    {
        std::cout<<"Not Found"<<std::endl;
    }
    return 0;
  }