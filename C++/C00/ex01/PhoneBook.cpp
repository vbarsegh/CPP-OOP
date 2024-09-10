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
    {
        int right_align = 10 - len;
        while (right_align > 0)
        {
            std::cout << " ";
            right_align--;
        }
        std::cout << str;
    }
        std::cout << "|";
	return (1);
		
}
void    PhoneBook::get_all_contact()
{
    int i = 0;
    while (i < this->all_count_of_contacts)
    {
        std::cout << "---------------------------------------------" << std::endl;
        std::cout << "|        " << i << "|";
        len_contact_member(get_first_name(i));//geterner pti grvi
        len_contact_member(this->obj[i].last_name);
        len_contact_member(this->obj[i].nick_name);
        i++;
        std::cout << std::endl;
    }
    std::cout << "---------------------------------------------" << std::endl;

}