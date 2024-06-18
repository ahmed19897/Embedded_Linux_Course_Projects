template  <class T> 
class SmartPointer
{
private:
    T *p=nullptr;
public:
    SmartPointer(T *ptr=nullptr)
    :p(ptr)
    {

        p=new T;//creates the dynamically allocated memory so we can assign values in it later on using the * overloaded operator

    }
    T& operator*()
    {
        return *p;//return a lreference to the p private data memeber so we can assign value to it
    }
    ~SmartPointer()
    {
        delete p;
    }
};

int main()
{
     SmartPointer<int> sptr;
     *sptr=5;

    return 0;
}
