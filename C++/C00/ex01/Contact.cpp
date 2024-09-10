// #include <iostream>
#include "phonebook.hpp"
// #include "contact.hpp"
// void    PhoneBook::addd(int i, Contact obj)
// {
//     this->obj[i] = obj;
// }

void    Contact::set_members()
{
    std::cout << "first_name = ";
    getline(std::cin, this->first_name);
	check_first_name(first_name);
    std::cout << "last_name = ";
    getline(std::cin, this->last_name);
	check_last_name(last_name);
    std::cout << "nickname = ";
    getline(std::cin, this->nickname);
	check_nickname(nickname);
    std::cout << "phone_num = ";
  	getline(std::cin, this->phone_num);
	check_phone_num(phone_num);
    std::cout << "secret = ";
    getline(std::cin, this->secret);
	check_secret(secret);
}