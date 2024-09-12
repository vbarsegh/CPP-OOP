#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"

class Contact
{
    private:
        std::string first_name; 
        std::string last_name;
        std::string nick_name;
        std::string phone_num;
        std::string secret;
    public:
        void    set_first_name();
        void    set_last_name();
        void    set_nick_name();
        void    set_phone_num();
        void    set_secret();
        std::string get_first_name();
		std::string	get_last_name();
		std::string	get_nick_name();
		std::string	get_phone_num();
		std::string	get_secret();


};

#endif