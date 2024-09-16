#include <iostream>
#include "PhoneBook.hpp"
// #include "contact.hpp"
int check_len_i(std::string i);

PhoneBook::PhoneBook()
{
    // std::cout << "Constructor of PhoneBook called" << std::endl;
    all_count_of_contacts = 0;
}

PhoneBook::~PhoneBook()
{
    // std::cout << "Destructor of PhoneBook called" << std::endl;
}


int len_contact_member(std::string str)
{
    int	len = str.length();
	if (len > 10)
	{
		std::cout << str.substr(0, 9) << ".";
	}
    else
    {
        int right_align = 10 - len;
        while (right_align > 0)
        {
            std::cout << " ";
            right_align--;
        }
        std::cout << str;
    }
        std::cout << "|";
	return (1);
		
}
void    PhoneBook::get_all_contact()
{
    int j = 0;
    while (j < this->all_count_of_contacts)
    {
        std::cout << "---------------------------------------------" << std::endl;
		std::cout << "|";
		std::cout << std::setw(10) << j << "|";
        len_contact_member(this->obj[j].get_first_name());
        len_contact_member(this->obj[j].get_last_name());
        len_contact_member(this->obj[j].get_nick_name());
        j++;
        std::cout << std::endl;
    }
    std::string i;
    if (all_count_of_contacts != 0)
    {
        while (1)
        {
            std::cout << "---------------------------------------------" << std::endl;
            std::cout << "Please say what index qez khetaqrqreg@ -> ";
	        getline(std::cin, i);
            if (std::cin.eof())
                exit(1);
            if (check_len_i(i) == 1)
                break ;
        }
        int ind = i[0] - 48;
        if (ind >= 0 && ind < all_count_of_contacts)
        {
            this->my_cout(ind);
            // std::cout << ind << std::endl;
            // std::cout << this->obj[ind].get_first_name() << std::endl;
            // std::cout << this->obj[ind].get_last_name() << std::endl;
            // std::cout << this->obj[ind].get_nick_name() << std::endl;
            // std::cout << this->obj[ind].get_phone_num() << std::endl;
            // std::cout << this->obj[ind].get_secret() << std::endl;
        }
        else
        {
            while (ind < 0 || ind >= all_count_of_contacts)
            {
                std::cout << "Please say what (correct) index qez khetaqrqreg@ -> ";
                getline(std::cin, i);
                if (std::cin.eof())
                    exit(1);
                ind = i[0] - 48;
            }
            this->my_cout(ind);
            // std::cout << ind << std::endl;
            // std::cout << this->obj[ind].get_first_name() << std::endl;
            // std::cout << this->obj[ind].get_last_name() << std::endl;
            // std::cout << this->obj[ind].get_nick_name() << std::endl;
            // std::cout << this->obj[ind].get_phone_num() << std::endl;
            // std::cout << this->obj[ind].get_secret() << std::endl;
        }
    }
    else
	{
		std::cout << "You don't have any contact right now" << std::endl;
	}
}

int check_len_i(std::string i)
{
    int len = i.length();

    return (len);
}

void    PhoneBook::my_cout(int ind)
{
    std::cout << ind << std::endl;
    std::cout << this->obj[ind].get_first_name() << std::endl;
    std::cout << this->obj[ind].get_last_name() << std::endl;
    std::cout << this->obj[ind].get_nick_name() << std::endl;
    std::cout << this->obj[ind].get_phone_num() << std::endl;
    std::cout << this->obj[ind].get_secret() << std::endl;
}