#include <iostream>
#include "PhoneBook.hpp"

int main()
{
    PhoneBook   user;
    std::string str_in;
    int i = 0;
    std::cout << "Command ADD: Added new Contact." << std::endl;
	std::cout << "Command SEARCH: searching and showing contacts." << std::endl;
	std::cout << "Command EXIT: Closing programm." << std::endl;
    std::cout << "Please enter the command you need" << std::endl;
    while (1)
    {
        std::getline(std::cin, str_in);
        if (std::cin.eof())
            break;
        if (!str_in.empty())
        {
            std::cout << "Please enter the command you need" << std::endl;
            if (str_in == "ADD")
            {
                if (i == 3)
                    i = 0;
                user.set_members(i);
                i++;
            }
            else if (str_in.compare("SEARCH") == 0)
                user.get_all_contact();
            else if (str_in == "EXIT")
                exit (0);
            else
                std::cout << "Wrong input !!!" << std::endl;
        }
    }
    
}