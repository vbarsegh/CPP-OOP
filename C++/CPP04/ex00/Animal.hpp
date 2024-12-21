#pragma once

#include <iostream>
#include <string>

class Animal
{
protected:
    std::string type;
public:
    Animal();
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    std::string getType(void) const;
    virtual void    makeSound() const;
    void    set_type(std::string);
    virtual ~Animal();
};

