#include "Dog.hpp"

Dog::Dog()
{
    set_type("Dog");
    DogBrain = new Brain();
    std::cout << "Dog default ctor is called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
    this->DogBrain = new Brain(*(other.DogBrain));
    std::cout << "Dog copy ctor is called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog op+ is called" << std::endl;
    if (this == &other)
        return (*this);
    delete this->DogBrain;
    // this->DogBrain = new Brain();
    // this->DogBrain = other.DogBrain;//shallow copy
    this->DogBrain = new Brain(*(other.DogBrain));

    // this->type = other.type;
    Animal::operator=(other);//or *this = Animal::operator=(other);
    return (*this);
}

void    Dog::makeSound() const
{
    std::cout << "Dog::haaaaaaafffff" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog dtor is called" << std::endl;
    delete DogBrain;
}