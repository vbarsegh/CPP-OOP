#pragma once

#include <iostream>
#include <cstddef>
#include <sstream>
#include <iomanip>
class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();
public:
    static void convert(const std::string& literal);
};

int check_type(const std::string& literal);

void	convert_char(const std::string& literal);

int allElemsIsDigit(const std::string& literal);
void	convert_int(const std::string& literal);

int isFloat(const std::string& literal);
void	convert_float(std::string& literal);

int contain_digit_dot_f(const std::string& literal);
int count_of_char(const std::string& literal, char c);
int isDouble(const std::string& literal);
void	convert_double(const std::string& literal);

int contain_digit_dot(const std::string& literal);
