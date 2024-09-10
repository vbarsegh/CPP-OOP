#include "phonebook.hpp"
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

void	check_first_name(std::string anun)
{
	while (only_spaces(anun) == 1 || check_only_letter(anun) == -1 )
	{
		std::cout << "Please write correct input" << std::endl;
		std::cout << "anun = ";
    	getline(std::cin, anun);
	}
}
void	check_last_name(std::string azganun)
{
	while (only_spaces(azganun) == 1 || check_only_letter(azganun) == -1)
	{
		std::cout << "Please write correct input" << std::endl;
		std::cout << "azganun = ";
    	 getline(std::cin, azganun);
	}
}
void	check_nickname(std::string makanun)
{
	while (only_spaces(makanun) == 1 || check_only_letter(makanun) == -1)
	{
		std::cout << "Please write correct input" << std::endl;
		std::cout << "makanun = ";
    	 getline(std::cin, makanun);
	}
}
void	check_phone_num(std::string heraxosahamar)
{
	while (only_spaces(heraxosahamar) == 1 || check_only_digit(heraxosahamar) == -1)
	{
		std::cout << "Please write correct input" << std::endl;
		std::cout << "heraxosahamar = ";
    	 getline(std::cin, heraxosahamar);
	}
}

void	check_secret(std::string gaxtniq)
{
	while (only_spaces(gaxtniq) == 1)
	{
		std::cout << "Please write correct input" << std::endl;
		std::cout << "heraxosahamar = ";
    	getline(std::cin, gaxtniq);
	}
}