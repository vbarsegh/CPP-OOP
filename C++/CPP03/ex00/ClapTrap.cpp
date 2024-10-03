#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hit_points(10), _energy_points(10), _attack_damage(0)
{
    std::cout << "default ctor is called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
    std::cout << "ctor with params is called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->_hit_points > 0 && this->_energy_points > 0)
        std::cout << "ClapTrap " << this->_name << " attacks " << target << ",causing " << this->_attack_damage << " points of damage!" << std::endl;
    else if (this->_hit_points <= 0)
        std::cout << "ClapTrap " << _name << " is dead!" << std::endl;
    else if (this->_energy_points <= 0)
        std::cout << "ClapTrap "<< _name << " has no energy" << std::endl;
    if (this->_energy_points > 0)
        this->_energy_points--;
}
void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount >= INT_MAX)
    {
        this->_hit_points = 0;
        return ;
    }
    if (this->_hit_points - amount < 0)
        this->_hit_points = 0;
    else
        this->_hit_points -= amount;
    std::cout << "takeDamage is called" << std::endl;
    
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_hit_points > 0 && this->_energy_points > 0)
    {
        std::cout << "beRepaired is called" << std::endl;
        if (amount >= INT_MAX)
            this->_hit_points = INT_MAX;
        else
        {
            if (this->_hit_points + amount < 0)//=>overflowa exe
                this->_hit_points = INT_MAX;
            else
                this->_hit_points += amount;
        }
        if (this->_energy_points > 0)
            this->_energy_points--;
    }
    else if (this->_hit_points <= 0)
        std::cout << "ClapTrap " << _name << " is dead!" << std::endl;
    else if (this->_energy_points <= 0)
        std::cout << "ClapTrap "<< _name << " has no energy" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "dtor is called" << std::endl;
}