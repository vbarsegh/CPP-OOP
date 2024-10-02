#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Clap_Ananun"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
    std::cout << "default ctor is called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
    std::cout << "ctor with params is called " << this->_name  << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << "copy ctor is called" << std::endl;
    // *this = other;//lav praktika chi
    this->_name = other._name;
    this->_hit_points = other._hit_points;
    this->_energy_points = other._energy_points;
    this->_attack_damage = other._attack_damage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
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

void ClapTrap::attack(const std::string& target)
{
    if (this->_hit_points > 0 && this->_energy_points > 0)
        std::cout << "ClapTrap " << this->_name << " attacks " << target << ",causing " << this->_attack_damage << " points of damage!" << std::endl;
    else
        std::cout << "ClapTrap can not do anything" << std::endl;
    if (this->_energy_points > 0)
        this->_energy_points--;
    std::cout << "ClapTrap current energy_points = " << _energy_points << std::endl;//checki hamar heto kmaqres handzneluc
    
}
void ClapTrap::takeDamage(unsigned int amount)
{
    // std::cout << "zzzzz = " << this->_hit_points << std::endl;
    // if (this->_hit_points)
    if (amount >= INT_MAX)
    {
        this->_hit_points = 0;
        return ;
    }
    std::cout <<" bo = " << this->_hit_points - amount<<std::endl;
    if (static_cast<int>(this->_hit_points - amount) < 0)
        this->_hit_points = 0;
    else
    {
        this->_hit_points -= amount;
        std::cout << "exav";
    }
    std::cout << "takeDamage is called" << std::endl;
    std::cout << "current hit_points = " << this->_hit_points << std::endl;//checki hamar heto kmaqres handzneluc
    
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

            if (static_cast<int>(this->_hit_points + amount) < 0)//=>overflowa exe,es casti pahy partadira ete chem anum sxala linum, overfloa ylnum
                this->_hit_points = INT_MAX;
            else
                this->_hit_points += amount;
        }
        if (this->_energy_points > 0)
            this->_energy_points--;
    }
    std::cout << "Repaitedi current hit_points = " << this->_hit_points << std::endl;//checki hamar heto kmaqres handzneluc//jnjel verjum

}

ClapTrap::~ClapTrap()
{
    std::cout << "dtor is called" << std::endl;
}