#include "Animal.hpp"

Animal::Animal()
{
    set_type("zibil");
    std::cout << "Animal default ctor is called" << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type)
{
    std::cout << "Animal copy ctor is called" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
    std::cout << "Animal op+ is called" << std::endl;
    if (this == &other)
        return (*this);
    this->type = other.type;
    return (*this);
}

void    Animal::set_type(std::string type)
{
    this->type = type;
}

std::string Animal::getType (void) const//consty grum enq vortev mainum Animal tipi pointernery cuyc en tallis const obyektneri vra,consty voncor garantiaya tali vor et obyekti vijaky(ira membernery) chenq poxi(chenq kara poxenq)
{
    return (this->type);
}

void    Animal::makeSound() const
{
    std::cout << "minchev chimanam inch Animala vonc dzen hanem?hetaqrqrir mardess" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal dtor is called" << std::endl;
}