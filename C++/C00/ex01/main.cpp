#include <iostream>
#include "PhoneBook.hpp"

int main()
{
    int i = 0;
    PhoneBook   user;
    std::string str_in;
    std::cout << "Command ADD: Added new Contact." << std::endl;
	std::cout << "Command SEARCH: searching and showing contacts." << std::endl;
	std::cout << "Command EXIT: Closing programm." << std::endl;
    std::cout << "Please enter the command you need" << std::endl;
    while (1)
    {
        if (!str_in.empty())
            std::cout << "Please enter the command you neeEEEEEd" << std::endl;
        std::getline(std::cin, str_in);
        if (std::cin.eof())
            break;
        if (str_in == "ADD")
        {
            if (i == 3)//8
                i = 0;
            user.set_members(i);
            i++;
        }
        else if (str_in.compare("SEARCH") == 0)
            user.get_all_contact();
        else if (str_in == "EXIT")
            exit (0);
    }
    
}