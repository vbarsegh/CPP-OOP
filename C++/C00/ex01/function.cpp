#include "PhoneBook.hpp"
// #include "contact.hpp"
int	check_only_letter(std::string str)
{
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if ((str[i] < 'a' || str[i] > 'z')
			|| (str[i] < 'A' && str[i] > 'Z'))
			return (-1);
	}
	return (1);
}

int	check_only_digit(std::string str)
{
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if ((str[i] < '0' || str[i] > '9'))
			return (-1);
	}
	return (1);
}
int	only_spaces(std::string anun)
{
	for(unsigned int i = 0; i < anun.length(); i++)
	{
		if (anun[i] != 32)
			return (-1);
	}
	return (1);
}

std::string	check_first_name(std::string first_name)
{
	while (only_spaces(first_name) == 1 || check_only_letter(first_name) == -1 )
	{
		std::cout << "Please write correct input" << std::endl;
		std::cout << "first_name = ";
    	getline(std::cin, first_name);
	}
	return (first_name);
}
std::string	check_last_name(std::string last_name)
{
	while (only_spaces(last_name) == 1 || check_only_letter(last_name) == -1)
	{
		std::cout << "Please write correct input" << std::endl;
		std::cout << "last_name = ";
    	 getline(std::cin, last_name);
	}
	return (last_name);
}
std::string	check_nickname(std::string nick_name)
{
	while (only_spaces(nick_name) == 1 || check_only_letter(nick_name) == -1)
	{
		std::cout << "Please write correct input" << std::endl;
		std::cout << "nick_name = ";
    	getline(std::cin, nick_name);
	}
	return (nick_name);
}
std::string	check_phone_num(std::string phone_num)
{
	while (only_spaces(phone_num) == 1 || check_only_digit(phone_num) == -1)
	{
		std::cout << "Please write correct input" << std::endl;
		std::cout << "phone_num = ";
    	getline(std::cin, phone_num);
	}
	return (phone_num);
}

std::string	check_secret(std::string secret)
{
	while (only_spaces(secret) == 1)
	{
		std::cout << "Please write correct input" << std::endl;
		std::cout << "secret = ";
    	getline(std::cin, secret);
	}
	return (secret);
}