#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    this->_name = "Ananun";
    this->_hit_points = 100;
    _energy_points = 50;
    _attack_damage = 20;
    std::cout << "ScavTrap default ctor is called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
    std::cout << "ScavTrap ctor with params is called" << std::endl;
    this->_name = name;
    this->_hit_points = 100;
    _energy_points = 50;
    _attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other)
{
    std::cout << "ScavTrap copy ctor is called" << std::endl;
    // *this = other;//lav praktika chi
    this->_name = other._name;
    this->_hit_points = other._hit_points;
    this->_energy_points = other._energy_points;
    this->_attack_damage = other._attack_damage;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    // std::cout << "copy assignment is called" << std::endl;
    if (this == &other)
        return (*this);
        this->_name = other._name;
    this->_hit_points = other._hit_points;
    this->_energy_points = other._energy_points;
    this->_attack_damage = other._attack_damage;
    return (*this);
}

void ScavTrap::attack(const std::string& target)
{
    if (this->_hit_points > 0 && this->_energy_points > 0)
        std::cout << "ScavTrap " << this->_name << " attacks " << target << ",causing " << this->_attack_damage << " points of damage!" << std::endl;
    else
        std::cout << "ScavTrap can not do anything" << std::endl;
    if (this->_energy_points > 0)
        this->_energy_points--;
    std::cout << "current energy_points = " << _energy_points << std::endl;//checki hamar heto kmaqres handzneluc
    
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap dtor is called" << std::endl;
}