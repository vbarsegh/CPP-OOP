#include "Cat.hpp"

Cat::Cat()
{
    set_type("Cat");
    CatBrain = new Brain();
    std::cout << "Cat default ctor is called" << std::endl;
}

Cat::Cat(const Cat&  other) : Animal(other)
{
    std::cout << "Cat copy ctor is called" << std::endl;
    this->CatBrain = new Brain();
    this->CatBrain = other.CatBrain;
    // type = other.type;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat op+ is called" << std::endl;
    if (this == &other)
        return (*this);
    delete this->CatBrain;
    this->CatBrain = new Brain();
    this->CatBrain = other.CatBrain;
    
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
    delete CatBrain;
}