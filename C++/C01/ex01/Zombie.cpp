#include "Zombie.hpp"

void Zombie::announce( void )
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie()
{
	std::cout << "Zombie default ctor is called" << std::endl;
    this->name = "NULL";
}

void Zombie::set_name(std::string name)
{
	this->name = name;
}


Zombie::Zombie(std::string name)
{
	std::cout << "Zombie ctor whit parametr is called" << std::endl;
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << "Zombie dtor is called ->";
	std::cout << this->name << " is destroyed" << std::endl;
}