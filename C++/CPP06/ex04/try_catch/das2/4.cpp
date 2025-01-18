#include <iostream>
#include <fstream>

class Exception
{
public:
    static int count_create;
    static int count_delete;
    Exception() {count_create++;}
    Exception(const Exception& other) {count_create++;}
    ~Exception() {count_delete++;}
};
int Exception::count_delete = 0;
int Exception::count_create = 0;

class FileTry
{
    std::ifstream& ifs;
public:
    FileTry(std::ifstream& ifs) : ifs(ifs)
    {}
    ~FileTry()
    {
        std::cout << "FileTry dtor is called\n";
        if (ifs.is_open())
        {
            ifs.close();
            std::cout << "Close file\n";
        }
    }
};

void    load_data(const char* path, int& x)
{
    std::ifstream  ifs;
    // FileTry file(ifs);
    FileTry *file = new FileTry(ifs);
    try{
        FileTry file(ifs);
        ifs.open(path);
        if (!ifs.is_open())
            throw Exception();
        ifs >> x;
    }
    catch(const Exception& e)
    {
        throw;//isk vor aranc et e-n nshelu enq poxancum henc et e-n a poxancum aranc copy anelu,dra hamare verjum create-i demy 1 tivna linum
    }
}

int main()
{
    int data {0};

    try{
        load_data("123", data);
        std::cout << data << std::endl;
    }
    catch(const Exception& ex){
        std::cout << "cr " << Exception::count_create << std::endl;
        std::cout << "de " << Exception::count_delete << std::endl;
    }
    std::cout << "cr " << Exception::count_create << std::endl;
    std::cout << "de " << Exception::count_delete << std::endl;
    return (0);
}
