#include <iostream>
#include "PhoneBook.hpp"
// #include "contact.hpp"

PhoneBook::PhoneBook()
{
    std::cout << "Constructor of PhoneBook called" << std::endl;
    all_count_of_contacts = 0;
}

PhoneBook::~PhoneBook()
{
    std::cout << "Destructor of PhoneBook called" << std::endl;
}

int len_contact_member(std::string str)
{
    int	len = str.length();
	if (len > 10)
	{
		std::cout << str.substr(0, 8) << ".";
	}
	else
		
}