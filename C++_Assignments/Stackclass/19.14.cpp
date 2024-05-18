//postfix evaluation enhancment -> can handle integers > 9
#include <iostream>
#include <string>
#include <iterator>
#include <map>
#include "Stacks.h"

using namespace std;

    struct toptwo
    {
        int x;
        int y;
    };

int ConvertToInt(char st[]);
bool Pop2TopElementsFromStack(Stacks<int>&,toptwo&);
bool Calculate(toptwo ,char,Stacks<int> &);
bool ExtractInts(string st,char arr[],int i,int * );

int main()
{
    Stacks <int> intstack;
    int top;
    string postfix;
    int i=0;
    char myarray[2];
    toptwo mytoptwo;
    int numberofcharsextracted=0;
//declare a multimap fpr operator preceding key and value
    multimap<char,int,less<int>> mymap;


//create a preceding table for all operators allowed
    mymap.insert(make_pair('+',1));
    mymap.insert(make_pair('-',1));
    mymap.insert(make_pair('*',5));
    mymap.insert(make_pair('/',5));
    mymap.insert(make_pair('%',5));
    mymap.insert(make_pair('^',1));

     cout<<"please enter the expression to evaluate:";
     getline(cin,postfix);

    for(int i=0;i<postfix.length();i++)
    {
        if(postfix.at(i)=='+' || postfix.at(i)=='-' || postfix.at(i)=='*' || postfix.at(i)=='/' || postfix.at(i)=='^' || postfix.at(i)=='%')
        {
            Pop2TopElementsFromStack(intstack,mytoptwo);
            Calculate(mytoptwo,postfix.at(i),intstack);
        }
        else
        {
            ExtractInts(postfix,myarray,i,& numberofcharsextracted );
            if(numberofcharsextracted>0)
            {
                intstack.push(ConvertToInt(myarray));//convert the character to string then push it
                myarray[0]='\0';
                myarray[1]='\0';
                i+=(numberofcharsextracted-1);//jump tp a place after the number of characters i extracted to continue
            
            }
            numberofcharsextracted=0;
        }
    }
    cout<<endl;
    cout<<(6+2)*15-8/4<<endl;
    cout<<"Total value is "<<intstack.Top()<<endl;
    cout<<endl;
    return 0;
}
int ConvertToInt(char st[])
{
    char *output;
    return strtol(st, &output, 10);
}

bool Pop2TopElementsFromStack(Stacks<int> &stack,toptwo &tw)
{ 
    tw.y=stack.Top();
    stack.pop(tw.y);
    tw.x=stack.Top();
    stack.pop(tw.x);
    return 0;
}

bool Calculate(toptwo tw,char op,Stacks<int> &st)
{
    switch (op)
    {
    case '+':
        st.push(tw.x+tw.y);
    break;

    case '-':
        st.push(tw.x-tw.y);
    break;

    case '*':
        st.push(tw.x*tw.y);
    break;

    case '/':
        st.push(tw.x/tw.y);
    break;

    case '%':
        st.push(tw.x%tw.y);
    break;

    case '^':
        st.push(tw.x^tw.y);
    break;
    
    default:
        cerr<<"illegal operator"<<endl;
    break;
    }
    return 0;
}

bool ExtractInts(string st,char arr[],int i,int * extractednumberofdigits)
{
    int j=0;
    while(!(st[i]==' ' || st[i]=='+'|| st[i]=='-'|| st[i]=='*'|| st[i]=='/'|| st[i]=='^'|| st[i]=='%'))
    {
        arr[j]=st[i];
        j++;
        i++;
    }
    *extractednumberofdigits=j;
    return 0;
}