#pragma once

#include "Animal.hpp"
#include <iostream>
#include <string>
#include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain* DogBrain;
    public:
        Dog();
        Dog(const Dog& other);
        Dog& operator=(const Dog& other);
        virtual void makeSound() const;
        virtual ~Dog();

};