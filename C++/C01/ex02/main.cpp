#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *str_p = &str;
    std::string &str_a = str;

    std::cout << "zut string  " << &str << std::endl;
    std::cout << "pointerov   " << str_p << std::endl;
    std::cout << "ampersandov " << &str_a << std::endl;

    std::cout << "esel value-ner@" << std::endl;
     std::cout << "zut string  " << str << std::endl;
    std::cout << "pointerov   " << *str_p << std::endl;
    std::cout << "ampersandov " << str_a << std::endl;
}