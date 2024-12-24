#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice()
{
    this->type = "ice";
    std::cout << "Ice default ctor is called" << std::endl;
}

Ice::Ice(const Ice&  other) :AMateria(other)
{
    std::cout << "Ice copy ctor is called" << std::endl;
}

Ice& Ice::operator=(const Ice& other)
{
    std::cout << "Ice copy assignment is called" << std::endl;
    if (this == &other)
        return (*this);
    // this->type = other.type;
    AMateria::operator=(other);
    return (*this);
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria* Ice::clone() const
{
	std::cout << "Ice clone Function Called" << std::endl;
    Ice* ice = new Ice();
    return (ice);
    // return new Ice();
}

Ice::~Ice()
{
    std::cout << "Ice dtor is called" << std::endl;
}