#include <iostream>
#include <fstream>

class Exception
{
public:
    static int count_create;
    static int count_delete;
    Exception() {count_create++;}
    Exception(const Exception& other) {std::cout << "mmm\n";count_create++;}
    ~Exception() {count_delete++;}
};
int Exception::count_delete = 0;
int Exception::count_create = 0;

void    load_data(const char* path, int& x)
{
    std::ifstream  ifs;
    try{
        ifs.open(path);
        if (!ifs.is_open())
            throw Exception();//1in angam create exav
        ifs >> x;
        ifs.close();
    }
    catch(const Exception& e)//poxancvav nuyn 22rd toxiny=>2rd-@ chstexcvav
    {
        ifs.close();
        throw e;//stex stexcvuma 2rdy(26rd toxi copy-n) u poxnacvum 41rd tox
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
}//4 hata create arvum Expectioni obyekt vortev sax tex aranc referacnova u ha copy a linum,2.cpp-um kgrem referacnov u ktesnenq vor 4hati poxaren 2 hata crete linum

//ays orinaovuzum einq cuyc tali vor class iskluchenia pti unena copy ctori irakanacum