
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
			convert_float(const_cast<std::string&>(literal));
			break ;
		case 3:
			//
			std::cout << "x равно 3" << std::endl;
			convert_double(literal);
			break ;
		default:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: nan" << std::endl;
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
	}
}

int check_type(const std::string& literal)
{
	cout << "li = " <<literal<<endl;
	cout << "li = " <<literal.size()<<endl;

 	if (literal.size() == 1 && !isdigit(literal[0]))
		return (0);//char
	if (allElemsIsDigit(literal) > 0)
	{
		cout << "paho";
		return (1);//int
	}
	if (isFloat(literal) > 0)
	{
		cout << "ekav\n";
		return (2);//float
	}
	if (isDouble(literal) > 0)
		return (3);
	cout << "mmmmmmm" <<endl;
	// if (literal == "nanf" || literal == "nan")
	if (literal == "-inff" || literal == "-inf"
		|| literal == "inff" || literal == "inf")
	{
		cout << "char: " << "impossible" << endl;
		cout << "int: " << "impossible" << endl;
		cout << "float: " << "inff" << endl;
		cout << "double: " << "inf" << endl;
	}
	else if (literal == "-nanf" || literal == "-nan"
		|| literal == "nanf" || literal == "nan")
	{
		cout << "char: " << "impossible" << endl;
		cout << "int: " << "impossible" << endl;
		cout << "float: " << "nanf" << endl;
		cout << "double: " << "nan" << endl;
	}
	return (777);
}
///////////////////////
int allElemsIsDigit(const std::string& literal)
{
	if (literal[0] == '\0')
		return (-1);
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
	if (literal[0] == '.' && literal[1] == 'f')
		return (-1);//float f = .f;//error
	if (contain_only_these_simbols(literal, ".f") != 1
		|| count_of_char(literal, '.') != 1 || count_of_char(literal, 'f') != 1)
		return (-1);
	if (literal[literal.size() - 1] != 'f')//esi u if eri hertakanutyuny lucuma en harcy vor .-@ f-ic araja 
		return (-1);
	return (1);
}

int contain_only_these_simbols(const std::string& literal, const char* sim)
{
	for (size_t i = 0; i < literal.size(); i++)
	{
		if (i == 0 && (literal[i] == '+' || literal[i] == '-'))
			continue;
		if ((literal[i] >='0' && literal[i] <= '9')
			|| check_sim(literal[i], sim) == 1)
			continue;
		return (-1);
	}
	cout << "beeeeeee\n";
	return (1);
}

int check_sim(char lit, const char* sim)
{
	int i = 0;
	while (sim[i])
	{
		if (sim[i] == lit)
			return (1);
		i++;
	}
	return (-1);
}

int count_of_char(const std::string& literal, char c)
{
	int count = 0;
	for (size_t i = 0; i < literal.size(); i++)
	{
		if (literal[i] == c)
			count++;
	}
	if (count != 1)
		return (count);
	return (count);
}


//////////////////////////////

////////////
int isDouble(const std::string& literal)
{

	if (contain_only_these_simbols(literal, ".") != 1 || count_of_char(literal, '.') != 1)
		return (-1);
	return (1);
}

// int contain_digit_dot(const std::string& literal)
// {
// 	for (size_t i = 0; i < literal.size(); i++)
// 	{
// 		if ((literal[i] >= '0' && literal[i] <= '9')
// 			|| literal[i] == '.')
// 			continue;
// 		return (-1);
// 	}
// 	return (1);
// }

//////////



/////////////
void	convert_char(const std::string& literal)
{
	char c = literal[0];
	cout << "c = " << c<<endl;
	if(!isascii(c))
		cout << "char: impossible" << endl;
	else if(!isprint(c))
		cout << "char: none displayable" << endl;
	else
		cout << "char: " << literal << endl;
	// if (liter)
	cout << "int: " << static_cast<int>(c) << endl;
	// if ()
	cout << "float: " << static_cast<float>(c) << ".0f" << endl;
	cout << "double: " << static_cast<double>(c) << ".0" << endl;
}

void	convert_int(const std::string& literal)
{
	std::stringstream ss(literal);
	long long num;
	ss >> num;
	if (ss.fail()) 
    	std::cout << "Error: Invalid number format" << std::endl;
	cout << "num="<<num<<endl;
	if (num > 127 || num < 0)
		cout << "char: impossible" << endl;
	else if (isprint(num))
		cout << "char: " << static_cast<char>(num) << endl;
	else
		cout << "char: Non displayable" << endl;
	if (num < -2147483648 || num > 2147483647)
		cout << "int: impossible" << endl;
	else
		cout << "int: " << num << endl;
	cout << "float: " << static_cast<float>(num) << ".0f" << endl;
	cout << "double: " << static_cast<double>(num) << ".0" << endl;
}

void	convert_float(std::string& literal)
{
	literal.resize(literal.size() - 1);
	cout << literal.size()<<endl;
	std::stringstream ss(literal);
	float f;
	ss >> f;
	if (ss.fail())
	{
    	std::cout << "Error: Invalid number format" << std::endl;
		// return ();
	}
	int all_zeros = 1;
	cout << "f = " << f << endl;
	unsigned int ind = literal.find('.');
	cout << "s = " <<literal.size() << endl;
	cout << "s = " << ind << endl;
	// if (ind == UINT_MAX)
	// 	ind = INT_MAX - 1;
	ind++;
	while (ind < literal.size())
	{
		if (literal[ind] == '0')
			ind++;
		else
		{
			all_zeros = 0;
			break ;
		}
	}
	if (all_zeros == 0)
		cout << "char: impossible" << endl;
	else
	{
		int num = static_cast<int>(f);
		cout << "num = " << num << endl;
		if (num > 127 || num < 0)
		cout << "char: impossible" << endl;
		else if (isprint(num))
			cout << "char: " << static_cast<char>(num) << endl;
		else
			cout << "char: Non displayable" << endl;
	}

	if (static_cast<long long>(f) < -2147483648 || static_cast<long long>(f) > 2147483647)
		cout << "int: impossible" << endl;
	else
		cout << "int: " << static_cast<int>(f) << endl;
	if (all_zeros == 1)
	{
		cout << "float: " << std::fixed << std::setprecision(1)<< f << "f" << endl;
		std::cout << "doubleeee: " << std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl;
	}
	else
	{
		cout << "float: " << f << "f" << endl;
		cout << "doublee: " << static_cast<double>(f) << endl;
	}
}

void	convert_double(const std::string& literal)
{
	std::stringstream ss(literal);
	double d;

	ss >> d;
	if (ss.fail())
	{
    	std::cout << "Error: Invalid number format" << std::endl;
		// return ();
	}
	int all_zeros = 1;
	unsigned int ind = literal.find('.');
	ind++;
	while (ind < literal.size())
	{
		if (literal[ind] == '0')
			ind++;
		else
		{
			all_zeros = 0;
			break ;
		}
	}
	if (all_zeros == 0)
		cout << "char: impossible" << endl;
	else
	{
		int num = static_cast<int>(d);
		cout << "num = " << num << endl;
		if (num > 127 || num < 0)
		cout << "char: impossible" << endl;
		else if (isprint(num))
			cout << "char: " << static_cast<char>(num) << endl;
		else
			cout << "char: Non displayable" << endl;
	}
	cout << "xi = " << static_cast<long long>(d) << endl;
	if (static_cast<long long>(d) < -2147483648 || static_cast<long long>(d) > 2147483647)
		cout << "int: impossible" << endl;
	else
		cout << "int: " << static_cast<int>(d) << endl;
	if (all_zeros == 1)
	{
		cout << "float: " << static_cast<double>(d) << ".0f" << std::endl;
		cout << "doublee: " << d << ".0" << endl;
	}
	else
	{
		cout << "float: " << static_cast<float>(d) << "f" << endl;
		cout << "double: " << d << endl;
	}
}
