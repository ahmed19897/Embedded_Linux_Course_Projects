#include <fstream>
#include <iostream>
#ifndef CACHEMANAGER_H
#define CACHEMANAGER_H

class CacheManager
{
private:
    std::fstream ifs;
    char mystring[1000];
public:
    void WriteCache(std::string chachevalue)
    {
        ifs.open("myfile.txt",std::ios::out|std::ios::in|std::ios::trunc);
        //if we couldn't open the file then we need to exit
        if(!ifs)
        {
            std::cerr<<"file couldn't be opened"<<std::endl;
            exit(EXIT_FAILURE);
        }
        else
        {
            ifs<<chachevalue;
            ifs<<'\n';
            ifs.close();
        }
    }
    char* GetCache(void)
    {
        ifs.open("myfile.txt",std::ios::in);
        if(!ifs)
        {
            std::cerr<<"file couldn't be opened"<<std::endl;
            exit(EXIT_FAILURE);
        }
        else
        {
            ifs.getline(mystring,sizeof(mystring),'\n');
            ifs.close();
        }
        return &mystring[0];
    }
};



#endif
