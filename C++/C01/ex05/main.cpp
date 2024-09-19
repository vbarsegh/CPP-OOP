#include "Harl.hpp"

int main()
{
	std::string	str;
    Harl	obj;


	std::cout << "Enter level -> ";
	getline(std::cin ,str);
	obj.complain(str);
}