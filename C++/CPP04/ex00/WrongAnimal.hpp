#pragma once

#include <iostream>
#include <string>

class WrongAnimal
{
protected:
    std::string type;
public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& other);
    WrongAnimal& operator=(const WrongAnimal& other);
    std::string getType(void) const;
    void    makeSound() const;
    void    set_type(std::string);
    virtual ~WrongAnimal();
};

