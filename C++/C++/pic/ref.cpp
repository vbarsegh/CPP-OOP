#include <iostream>


int main()
{
    // std::string s = "Hello";
    const std::string &ref = "ffff";  // Работает нормально
     ref[0] = 'a';
    std::cout << ref << std::endl;
}