#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "Contact.hpp"

class PhoneBook
{
    private:
		int	all_count_of_contacts;
        Contact obj[3];//esi 8ksarqes handzneluc
    public:
    	PhoneBook();
    	~PhoneBook();
		void    get_all_contact();
		void    set_members(int i);
		void	my_cout(int ind);
};

int			check_only_letter(std::string str);
int			check_only_digit(std::string str);
std::string	check_first_name(std::string first_name);
std::string	check_last_name(std::string last_name);
std::string	check_nickname(std::string nickname);
std::string	check_phone_num(std::string phone_num);
std::string	check_secret(std::string secret);
int			len_contact_member(std::string str);

#endif