#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    set_type("zibil");
    std::cout << "WrongAnimal default ctor is called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type)
{
    std::cout << "WrongAnimal copy ctor is called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    std::cout << "WrongAnimal op+ is called" << std::endl;
    if (this == &other)
        return (*this);
    this->type = other.type;
    return (*this);
}

void    WrongAnimal::set_type(std::string type)
{
    this->type = type;
}

std::string WrongAnimal::getType (void) const//consty grum enq vortev mainum WrongAnimal tipi pointernery cuyc en tallis const obyektneri vra,consty voncor garantiaya tali vor et obyekti vijaky(ira membernery) chenq poxi(chenq kara poxenq)
{
    return (this->type);
}

void    WrongAnimal::makeSound() const
{
    std::cout << "minchev chimanam inch WrongAnimala vonc dzen hanem?hetaqrqrir mardess" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal dtor is called" << std::endl;
}