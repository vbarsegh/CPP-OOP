#include "ScalarConverter.hpp"

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: Invalid number of arguments." << std::endl;
        return (11);
    }
    else
    {   
        (void)argv;
        double a = 11.f;
        std::cout << "a = " << a << "\n";
        ScalarConverter::convert(argv[1]);
        // float nu = 12123154323234567898765432345678987654345678.f;
        // std::cout << "nu = " <<nu << std::endl;
    }
}