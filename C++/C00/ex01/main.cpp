#include <iostream>
#include "PhoneBook.hpp"

int main()
{
    PhoneBook   user;
    std::string str_in;
    int i = 0;
    while (1)
    {
        std::cout << "Please enter the command you need" << std::endl;
        std::getline(std::cin, str_in);
        if (str_in == "ADD")
        {
            if (i == 3)
            	i = 0;
            user.set_members(i);
            i++;
        }
		else if (str_in.compare("SEARCH") == 0)
            user.get_all_contact();

    }
    
}