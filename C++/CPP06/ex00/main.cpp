#include "ScalarConverter.hpp"
#include <float.h>
int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: Invalid number of arguments." << std::endl;
        return (11);
    }
    else
    {   
        // (void)argv;
        // double a = DBL_MAX;
        
        // std::cout << "a = " << std::fixed << static_cast<float>(a) << "\n";
        // float f = 12f;//compile chi linum
        // std::cout << "f = " << f << "\n";
        ScalarConverter::convert(argv[1]);
        // float nu = 12123154323234567898765432345678987654345678.f;
        // std::cout << "nu = " <<nu << std::endl;
    }
}

