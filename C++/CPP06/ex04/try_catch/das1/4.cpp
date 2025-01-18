#include <iostream>
#include <fstream>


void    load_data(const char* path, int& x)
{
    std::ifstream  ifs;
    ifs.exceptions(std::ios::failbit);//dlya vkluchenia generacii isklyucheniy

    try{
        ifs.open(path);
        ifs >> x;
        ifs.close();
    }
    catch(...)//es nsh. e vor blok catch-@ kbrni cankacac 
    {
        ifs.close();
        throw;
    }
}

int main()
{
    int data {0};

    try{
        load_data("123", data);
        std::cout << data << std::endl;
    }
    catch(const std::exception& ex){
        std::cout << "Error read data from file." << std::endl;
    }
    return (0);
}