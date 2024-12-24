#include "Character.hpp"
#include "AMateria.hpp"

Character::Character() : name("ananun")
{
    for(int i = 0; i < 4; i++)
        inventory[i] = NULL;
    std::cout << "Charachter default ctor is called" << std::endl;
}

Character::Character(const std::string new_name) : name(new_name)
{
	for(int i = 0; i < 4; i++)
        inventory[i] = NULL;
    std::cout << "Charachter ctor with param is called" << std::endl;
}


Character::Character(const Character& other) : name(other.name)
{
    std::cout << "Charachter copy ctor is called" << std::endl;
	for(int i = 0; i < 4; i++)
    {
        if (other.inventory[i] != NULL)
            this->inventory[i] = other.inventory[i]->clone();
        else
            this->inventory[i] = NULL;
    }
}

Character& Character::operator=(const Character& other)
{
    std::cout << "Charachter copy assignment is called" << std::endl;
	if(this == &other)
		return (*this);
	this->name = other.name;
	// for(int i = 0; i < 4; i++)
	// {
	// 	if (this->inventory[i] != NULL)
	// 		delete this->inventory[i];
	// }
	for(int i = 0; i < 4; i++)
    {
        delete this->inventory[i];
        if (other.inventory[i] != NULL)
        {
            this->inventory[i] = other.inventory[i]->clone();
        }
        else
            this->inventory[i] = NULL;
    }
	return (*this);
}


std::string const& Character::getName() const
{
    return (this->name);
}

void Character::equip(AMateria* m)
{
    if (!m)
        return;
    for (int j = 0; j < 4; j++)
    {
        if (this->inventory[j] == m)
        {
			std::cout << "already have this AMateria" << std::endl;
			return ;
		}
    }
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory[i] == NULL)
        {
            this->inventory[i] = m;
            std::cout << "Materia equipped at slot " << i << std::endl;
            return;
        }
    }
    std::cout << "All slots are busy; cannot add another materia." << std::endl;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx > 3)
    {
        std::cout << "Invalid index; cannot unequip materia." << std::endl;
        return;
    }
	std::cout << "Unequip called" << std::endl;
    if (this->inventory[idx] != NULL)
    {
		this->inventory[idx] = NULL;
    }
	else
		std::cout << "Slot " << idx << " is already empty." << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
    {
        std::cout << "Invalid index; cannot unequip materia." << std::endl;
        return;
    }
	std::cout << "use is called" << std::endl;
	if (this->inventory[idx] != NULL)
		this->inventory[idx]->use(target);
	else
		std::cout << "Slot " << idx << " is empty; no materia to use." << std::endl;
}

Character::~Character()
{
    std::cout << "Charachter dtor is called" << std::endl;
    for (int i = 0; i < 4; i++)
        delete this->inventory[i];
}