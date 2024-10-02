#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
    this->_name = "Diamond_Ananun";
    this->_hit_points = FragTrap::_hit_points;
    this->_energy_points = ScavTrap::_energy_points;
    this->_attack_damage = FragTrap::_attack_damage;
    std::cout << "DiamondTrap default ctor is called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap("FSDLFDSLK")
{
    this->_name = name;
    // std::cout << "\n\n";
    // std::cout << "_name = " << ClapTrap::_name;
    // std::cout << "\n\n";

    // ClapTrap::_name = name + "_clap_name";
    this->_hit_points = 100;
    this->_energy_points = ScavTrap::_energy_points;
    this->_attack_damage = FragTrap::_attack_damage;
    std::cout << "DiamondTrap ctor with params is called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
{
    std::cout << "DiamondTrap copy ctor is called" << std::endl;
    // *this = other;//lav praktika chi
    this->_name = other._name;
    this->_hit_points = other._hit_points;
    this->_energy_points = other._energy_points;
    this->_attack_damage = other._attack_damage;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
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

void DiamondTrap::whoAmI()
{
    std::cout << "Diamond name is " << this->_name << " and ClapTrap name is " << this->ClapTrap::_name << std::endl;
}



DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap dtor is called" << std::endl;
}