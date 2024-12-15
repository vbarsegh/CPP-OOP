#include "AMateria.hpp"

AMateria::AMateria()
{
    std::cout << "AMateria default ctor is called" << std::endl;
}

AMateria::AMateria(std::string const& type)
{
    std::cout << "AMateria ctor with parametr is called" << std::endl;
    this->type = type;
}
AMateria::AMateria(const AMateria&  other)
{
    std::cout << "AMateria copy ctor is called" << std::endl;
    type = other.type;//?
}

AMateria& AMateria::operator=(const AMateria& other)
{
    std::cout << "AMateria copy assignment is called" << std::endl;
    if (this == &other)
        return (*this);
    this->type = other.type;//?
    return (*this);
}

std::string const& AMateria::getType() const //Returns the materia type
{
    return (this->type);
}

void AMateria::use(ICharacter& target)
{
    std::cout << "Only AMaterias use is called,and the targets name is " << target.getName() << std::endl;
}///?


AMateria::~AMateria()
{
    std::cout << "AMateria dtor is called" << std::endl;

}