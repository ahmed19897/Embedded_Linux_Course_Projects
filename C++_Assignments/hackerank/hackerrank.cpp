class Person
{
    public:
        string GetName(void)const;
        void SetName(string );
        virtual void  getdata();
        virtual void putdata(void)const;
        
        int GetAge(void)const;
        void SetAge(int);
    private:
        string name;
        unsigned int age;
};
string Person::GetName(void)const
{
    return name ;
}
void Person::SetName(string userinput)
{
    name=userinput;
}      
int Person::GetAge(void)const
{
    return  age;
}
void Person::SetAge(int userinput)
{
    age=userinput;
}
void  Person::getdata()
{
    string username;
    int userage;
    cin>>username>>userage;
    name=username;
    age=userage;
}
void Person::putdata(void)const
{
    cout<<GetName()<<" "<<GetAge()<<std::endl;
}


int profID=1;
int stuID=1;




class Professor:public Person
{
    public:
        Professor();
        virtual void  getdata();
        virtual void putdata(void)const;
        
        int  Getpublications(void)const;
        void Pushpublications(int publication);
    private:
        int publications;
        int cur_id;
};
Professor::Professor(void)
:cur_id(profID)
{
    profID++;
}
void Professor::getdata()
{
    string username;
    int userage;
    int userpub;
    std::cin>>username>>userage>>userpub;
    SetName(username) ;
    SetAge(userage) ;
    Pushpublications(userpub);
}
void Professor::putdata(void)const
{
    std::cout<<this->GetName()<<" "<<this->GetAge()<<" "<<this->Getpublications()<<" "<< cur_id<<std::endl;
}
int  Professor::Getpublications(void)const
{
    return  publications;
}
void Professor::Pushpublications(int publication)
{
    publications=publication;
}






class Student:public Person
{
    public:
        Student(void);
        virtual void  getdata();
        virtual void putdata(void)const;
        int GetSumOfMarks(void)const;

        
    private:
        int Mark[6];
        int cur_id;
               
};
Student::Student(void)
:cur_id(stuID)
{
    stuID++; 
}

int Student::GetSumOfMarks(void)const
{
    int sum=0;
    for(auto items:Mark)
    {
       sum+=items;
    }
    return sum;
}
void Student::getdata()
{
    string username;
    int userage;
    int userpub;
    int localMark[6];
    std::cin>>username>>userage;
    for(int i=0;i<6;i++)
    {
        cin>>localMark[i];
        Mark[i]=localMark[i];
    }
    SetName(username) ;
    SetAge(userage) ;
}
void Student::putdata(void)const
{
std::cout<<this->GetName()<<" "<<this->GetAge()<<" "<< GetSumOfMarks()<<" "<<cur_id<<std::endl;
}