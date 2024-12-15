#include "Ice.hpp"

Ice::Ice()// : AMateria("ice")
{
    this->type = "ice";
    std::cout << "Ice default ctor is called" << std::endl;
}

Ice::Ice(const Ice&  other)//:AMateria(other)stex senc chenq anum,vortev mer base class AMaterian abstracta u ira obyekt chenq kara stexcenq
{
    std::cout << "Ice copy ctor is called" << std::endl;
    type = other.type;//?
}

Ice& Ice::operator=(const Ice& other)
{
    std::cout << "Ice copy assignment is called" << std::endl;
    if (this == &other)
        return (*this);
    this->type = other.type;//?
    return (*this);
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria* Ice::clone() const
{
    Ice* ice = new Ice();
    ice->type = this->getType();
    return (ice);
    // return new Ice(*this);
}


Ice::~Ice()
{
    std::cout << "Ice dtor is called" << std::endl;
}