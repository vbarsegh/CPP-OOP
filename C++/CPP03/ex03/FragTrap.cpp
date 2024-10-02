#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    this->_name = "Frag_Ananun";
    this->_hit_points = 100;
    _energy_points = 100;
    _attack_damage = 30;
    std::cout << "FragTrap default ctor is called" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
    std::cout << "FragTrap ctor with params is called" << std::endl;
    this->_name = name;
    this->_hit_points = 100;
    _energy_points = 100;
    _attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap& other)
{
    std::cout << "FragTrap copy ctor is called" << std::endl;
    // *this = other;//lav praktika chi
    this->_name = other._name;
    this->_hit_points = other._hit_points;
    this->_energy_points = other._energy_points;
    this->_attack_damage = other._attack_damage;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
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


void FragTrap::highFivesGuys()
{
    if (this->_hit_points > 0)
        std::cout << "FragTrap High five Broo" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap dtor is called" << std::endl;
}