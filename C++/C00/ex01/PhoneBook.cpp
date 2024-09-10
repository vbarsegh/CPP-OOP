#include <iostream>
#include "phonebook.hpp"
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

void    PhoneBook::get_all_contact()
{
    int i = 0;
    while (i < this->all_count_of_contacts)
    {
        std::cout << "_____________" << std::endl;
        std::cout << "|         " << i << "|";
        len_contact_member(this->obj[i].first_name);
    }
}