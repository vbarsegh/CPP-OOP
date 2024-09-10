#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"

class Contact
{
    public:
        std::string first_name; 
        std::string last_name;
        std::string nickname;
        std::string phone_num;
        std::string secret;
    public:
        void    set_members();
};

#endif