#include <iostream>
#include "phonebook.hpp"

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
            if (i == 7)
            	i = 0;
            user.obj[i].set_members();
            i++;
            if (user.all_count_of_contacts < 7)
                user.all_count_of_contacts++;
        }
		else if (str_in.compare("SEARCH") == 0)
            user.get_all_contact();

    }
    
}
