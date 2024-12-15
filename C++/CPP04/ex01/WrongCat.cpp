#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    set_type("WrongCat");
    std::cout << "WrongCat default ctor is called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    std::cout << "WrongCat copy ctor is called" << std::endl;
    // type = other.type;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    std::cout << "WrongCat op+ is called" << std::endl;
    if (this == &other)
        return (*this);
    this->type = other.type;
    return (*this);
}

void    WrongCat::makeSound() const
{
    std::cout << "WrongCat::myaaauuu" << std::endl;
}


WrongCat::~WrongCat()
{
    std::cout << "WrongCat dtor is called" << std::endl;
}