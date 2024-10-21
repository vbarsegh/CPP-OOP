#include "Cat.hpp"

Cat::Cat()
{
    set_type("Cat");
    std::cout << "Cat default ctor is called" << std::endl;
}

Cat::Cat(const Cat& other) :Animal(other)
{
    std::cout << "Cat copy ctor is called" << std::endl;
    // type = other.type;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat op+ is called" << std::endl;
    if (this == &other)
        return (*this);
    this->type = other.type;
    return (*this);
}

void    Cat::makeSound() const
{
    std::cout << "Cat::myaaauuu" << std::endl;
}


Cat::~Cat()
{
    std::cout << "Cat dtor is called" << std::endl;
}