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
        ScalarConverter::convert(argv[1]);
    }
}