#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "contact.hpp"

class PhoneBook
{
    public:
		int	all_count_of_contacts;
        Contact obj[8];
    public:
		void    get_all_contact();
};

int		check_only_letter(std::string str);
int		check_only_digit(std::string str);
void	check_first_name(std::string first_name);
void	check_last_name(std::string last_name);
void	check_nickname(std::string nickname);
void	check_phone_num(std::string phone_num);
void	check_secret(std::string secret);
int		len_contact_member(std::string str);

#endif