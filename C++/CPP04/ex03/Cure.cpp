#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure()
{
    this->type = "cure";
    std::cout << "Cure default ctor is called" << std::endl;
}

Cure::Cure(const Cure&  other) : AMateria(other)
{
    std::cout << "Cure copy ctor is called" << std::endl;
    // type = other.type;//?
}

Cure& Cure::operator=(const Cure& other)
{
    std::cout << "Cure copy assignment is called" << std::endl;
    if (this == &other)
        return (*this);
    // this->type = other.type;//?
    AMateria::operator=(other);
    return (*this);
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria* Cure::clone() const
{
	std::cout << "Cure clone Function Called" << std::endl;
    // Cure* cure = new Cure();  
    // return (cure);
    return (new Cure(*this));//Cure-i copy ctori kanch
}

Cure::~Cure()
{
    std::cout << "Cure dtor is called" << std::endl;
}