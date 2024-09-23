#include "Harl.hpp"

Harl::Harl()
{
    std::cout << "default ctor is called" << std::endl;
}

Harl::~Harl()
{
    std::cout << "dtor is called" << std::endl;
}

void Harl::debug( void )
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}


void Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You did not put	enough bacon in my burger! If you did, I would not be asking for more!" << std::endl;
}


void Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I have been coming foryears whereas you started working here since last month." << std::endl;
}

void Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level )
{
	void (Harl::*ptr_d)() = this->debug();
	void (Harl::*ptr_i)() = &Harl::info;
	void (Harl::*ptr_w)() = &Harl::warning;
	void (Harl::*ptr_e)() = &Harl::error;

	void	(Harl::*func_arr[])() = {ptr_d, ptr_i, ptr_w, ptr_e};
	std::string	str[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (str[i] == level)
			(this->*func_arr[i])();
	}
}
