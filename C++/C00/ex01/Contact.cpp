// #include <iostream>
#include "PhoneBook.hpp"
// #include "contact.hpp"
// void    PhoneBook::addd(int i, Contact obj)
// {
//     this->obj[i] = obj;
// }

void    PhoneBook::set_members(int i)
{
    this->obj[i].set_first_name();
    this->obj[i].set_last_name();
    this->obj[i].set_nick_name();
    this->obj[i].set_phone_num();
    this->obj[i].set_secret();
	if (this->all_count_of_contacts < 3)
                this->all_count_of_contacts++;
    // std::cout << "nickname = ";
    // getline(std::cin, this->nick_name);
	// check_nickname(nick_name);
    // std::cout << "phone_num = ";
  	// getline(std::cin, this->phone_num);
	// check_phone_num(phone_num);
    // std::cout << "secret = ";
    // getline(std::cin, this->secret);
	// check_secret(secret);
}

void    Contact::set_first_name()
{
    std::string first_name;
    std::cout << "first_name = ";
    getline(std::cin, first_name);
    check_first_name(first_name);
    this->first_name = first_name;
}

void    Contact::set_last_name()
{
    std::string last_name;
    std::cout << "last_name = ";
    getline(std::cin, last_name);
    check_last_name(last_name);
    this->last_name = last_name;
}

void    Contact::set_nick_name()
{
    std::string nick_name;
    std::cout << "nick_name = ";
    getline(std::cin, nick_name);
	check_nickname(nick_name);
    this->nick_name = nick_name;
}

void    Contact::set_phone_num()
{
    std::string phone_num;
    std::cout << "phone_num = ";
    getline(std::cin, phone_num);
	check_phone_num(phone_num);
    this->phone_num = phone_num;
}

void    Contact::set_secret()
{
    std::string secret;
    std::cout << "secret = ";
    getline(std::cin, secret);
	check_secret(secret);
    this->secret = secret;
}

std::string	Contact::get_first_name()
{
	return (this->first_name);
}

std::string	Contact::get_last_name()
{
	return (this->last_name);
}

std::string	Contact::get_nick_name()
{
	return (this->nick_name);
}

std::string	Contact::get_phone_num()
{
	return (this->phone_num);
}

std::string	Contact::get_secret()
{
	return (this->secret);
}
