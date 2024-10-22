#pragma once

#include <iostream>
#include <string>

class WrongAnimal
{
protected:
    std::string type;
    void    set_type(std::string);
public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& other);
    WrongAnimal& operator=(const WrongAnimal& other);
    std::string getType(void) const;
    void    makeSound() const;
    virtual ~WrongAnimal();
};

