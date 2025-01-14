#include "ScalarConverter.hpp"
using std::cout;
using std::endl;
ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter default ctor is called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	std::cout << "ScalarConverter copy ctor is called" << std::endl;
	*this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	std::cout << "ScalarConverter operator= is called" << std::endl;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter dtor is called" << std::endl;
}

void ScalarConverter::convert(const std::string& literal)
{
	switch(check_type(literal))
	{
		case 0:
		///
			std::cout << "x равно 0" << std::endl;
			convert_char(literal);
			break ;
		case 1:
			///
			 std::cout << "x равно 1" << std::endl;
			convert_int(literal);
			break ;
		case 2:
			///
			 std::cout << "x равно 2" << std::endl;
			break ;
		case 3:
			//
			 std::cout << "x равно 3" << std::endl;
			break ;
		default:
			std::cout << "impossible" << std::endl;
	}
}

int check_type(const std::string& literal)
{
	if (literal.size() == 1 && isprint(literal[0]) && !isdigit(literal[0]))
		return (0);//char
	if (allElemsIsDigit(literal) > 0)
	{
		cout << "paho";
		return (1);//int
	}
	if (isFloat(literal) > 0)
		return (2);//float
	if (isDouble(literal) > 0)
		return (3);
	cout << "mmmmmmm";
	return (777);
}
///////////////////////
int allElemsIsDigit(const std::string& literal)
{
	for (size_t i = 0; i < literal.size(); i++)
	{
		if ((i == 0) && (literal[i] == '+' || literal[i] == '-'))
			continue ;
		if (literal[i] < '0' || literal[i] > '9')
		{
			cout << "yhn";
			return (-1);
		}
	}
	return (1);
}
/////////////////////

/////////////////////
int isFloat(const std::string& literal)
{

	if (contain_digit_dot_f(literal) != 1
		|| count_of_f(literal) != 1 || count_of_dot(literal) != 1)
		return (-1);
	if (literal[literal.size() - 1] != 'f')//esi u if eri hertakanutyuny lucuma en harcy vor .-@ f-ic araja 
		return (-1);
	return (1);
}

int contain_digit_dot_f(const std::string& literal)
{
	for (size_t i = 0; i < literal.size(); i++)
	{
		if ((literal[i] >='0' && literal[i] <= '9')
			|| literal[i] == 'f' || literal[i] == '.')
			continue;
		return (-1);
	}
	return (1);
}

int count_of_dot(const std::string& literal)
{
	int count = 0;
	for (size_t i = 0; i < literal.size(); i++)
	{
		if (literal[i] == '.')
			count++;
	}
	if (count != 1)
		return (-1);
	return (1);
}

int count_of_f(const std::string& literal)
{
	int count = 0;
	for (size_t i = 0; i < literal.size(); i++)
	{
		if (literal[i] == 'f')
			count++;
	}
	if (count != 1)
		return (-1);
	return (1);
}
//////////////////////////////

////////////
int isDouble(const std::string& literal)
{

	if (contain_digit_dot(literal) != 1 || count_of_dot(literal) != 1)
		return (-1);
	return (1);
}

int contain_digit_dot(const std::string& literal)
{
	for (size_t i = 0; i < literal.size(); i++)
	{
		if ((literal[i] >= '0' && literal[i] <= '9')
			|| literal[i] == '.')
			continue;
		return (-1);
	}
	return (1);
}

//////////



/////////////
void	convert_char(const std::string& literal)
{
	char c = literal[0];
	cout << "char: " << literal << endl;
	cout << "int: " << static_cast<int>(c) << endl;
	cout << "float: " << static_cast<float>(c) << ".0f" << endl;
	cout << "double: " << static_cast<double>(c) << ".0" << endl;
}

void	convert_int(const std::string& literal)
{
	long long num = std::atoi(literal.c_str());
	if (num < -2147483648 || num > 2147483647 || literal.size() > 10)
		cout << "impossible" << endl;
	if (num >= 0 && num <= 31)
		cout << "char: Non displayable" << endl;
	else
		cout << "char: " << static_cast<char>(num) << endl;
	cout << "int: " << num << endl;
	cout << "float: " << static_cast<float>(num) << ".0f" << endl;
	cout << "double: " << static_cast<double>(num) << ".0" << endl;
}