#include "Dog.hpp"

Dog::Dog()
{
    set_type("Dog");
    DogBrain = new Brain();
    std::cout << "Dog default ctor is called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Dog copy ctor is called" << std::endl;
    this->DogBrain = new Brain(*(other.DogBrain));
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog op+ is called" << std::endl;
    if (this == &other)
        return (*this);
    // delete this->DogBrain;
    // this->DogBrain = new Brain(*(other.DogBrain));
    *(this->DogBrain) = *(other.DogBrain);//kam senc kam verevi 2 toxov

    // this->type = other.type;
    Animal::operator=(other);
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