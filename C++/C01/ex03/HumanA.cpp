#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& club) : wp1(club)
{
    this->name = name;
    // this->wp1 = club;
    std::cout << "HumanA ctor with params is called" << std::endl;
}

HumanA::~HumanA()
{
    std::cout << "HumanA dtor is called" << std::endl;
}

void    HumanA::attack()
{
    std::cout << this->name << " attacks with their " << this->wp1.getType() << std::endl;
}