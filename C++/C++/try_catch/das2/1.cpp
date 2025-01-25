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

void    load_data(const char* path, int& x)
{
    std::ifstream  ifs;
    try{
        ifs.open(path);
        if (!ifs.is_open())
            throw Exception();//arajin angam stex stexcvav Exceptioni obyekty
        ifs >> x;
        ifs.close();
    }
    catch(const Exception e)//stex qani vor aranc referanca en 22rd toxum stexcvaci copyna=>uje 2 hat stexcvela
    {
        ifs.close();
        throw e;//veradarcnumm enq=>copyna veradarcvelu=>uje 3 hat stexcvav,ev es toxxic heto en verevi erku Exception obyektnery kmaqrven(count_delete-@ kdarnna 2) 
    }
}

int main()
{
    int data {0};

    try{
        load_data("123", data);
        std::cout << data << std::endl;
    }
    catch(const Exception ex){//29rd toxic galisa stex,u copy-i mijocov stexcvuma 4rd obj-n
        std::cout << "cr " << Exception::count_create << std::endl;
        std::cout << "de " << Exception::count_delete << std::endl;
    }//sranic hetoel,29rd toxi poxancvacy ev 41um stexcvac copy-n kmaqrven(count_delete-@ exav 4)
    std::cout << "cr " << Exception::count_create << std::endl;
    std::cout << "de " << Exception::count_delete << std::endl;
    return (0);
}//4 hata create arvum Expectioni obyekt vortev sax tex aranc referacnova u ha copy a linum,2.cpp-um kgrem referacnov u ktesnenq vor 4hati poxaren 2 hata crete linum