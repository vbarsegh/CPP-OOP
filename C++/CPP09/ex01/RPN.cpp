#include "RPN.hpp"

RPN::RPN()
{
	// cout << "RPN default ctor is called" << endl;
}

RPN::RPN(const RPN& other)
{
	cout << "RPN copy ctor is called" << endl;
	_elem = other._elem;
	st = other.st;
}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
		cout << "RPN operator= is called" << endl;
		_elem = other._elem;
		st = other.st;
	}
	return (*this);
}

int		RPN::check_what_operation_must_be_make(char operato_r)
{
	if (operato_r == '+')
		return (1);
	if (operato_r == '-')
		return (2);
	if (operato_r == '*')
		return (3);
	if (operato_r == '/')
		return (4);
	return (-1);
}

void    RPN::operation(char operato_r)
{
    if (st.size() < 2)
        throw std::runtime_error("can not do operation, because elem count will not suffice");
    long res;
	// if (st.empty())
	// 	cout << "eeeeeeeeee\n";
	long num2 = st.top();
	st.pop();
	long num1 = st.top();
	st.pop();
	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;
	switch(check_what_operation_must_be_make(operato_r))
	{
		case 1:
			res = num1 + num2;
			break ;
		case 2:
			res = num1 - num2;
			break ;
		case 3:
			// if (num1 * num2 > 2147483647)
			// 	throw std::runtime_error("result of operation in 2 numbers is larg than INT_MAX");
			res = num1 * num2;
			break ;
		case 4:
			if (num2 == 0)
				throw std::runtime_error("can not do / operation when haytarar is 0!");
			res = num1 / num2;
			break ;
	}
	if (res > INT_MAX)
		throw std::runtime_error("result of operation in 2 numbers is larg than INT_MAX");
	// std::cout<<res<<std::endl;
	st.push(static_cast<int>(res));
}

int    RPN::member_func(char* argv1)
{
    std::stringstream ss(argv1);
	std::stringstream to_int;
	std::string word;
	while (ss >> word)// Пока удаётся извлечь слово (разделённое пробелами)
	{
		// cout << "word->" << word << endl;
		if (word.size() != 1)
			throw std::runtime_error("elem size is not 1");
		if (isdigit(word[0]))
		{
			// cout << "yhn\n";
			to_int << word;
			to_int >> _elem;
			// cout << "tivy = " <<_elem << endl;
			st.push(_elem);
			to_int.clear();
		}
        else
        {
            operation(word[0]);
        }
	}
	if (st.size() != 1)
		throw std::runtime_error("elems and operators dont corresponding");
	return (st.top());
}

RPN::~RPN()
{
	// cout << "RPN dtor is called" << endl;
}