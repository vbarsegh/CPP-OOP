#pragma once

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain* CatBrain;
    public:
        Cat();
        Cat(const Cat& other);
        Cat& operator=(const Cat& other);
        virtual void makeSound() const;
        void    sett(std::string ideas){this->CatBrain->setBrain(ideas);}
        void    gett()
        {
            std::cout << "cat1-iny-> " << CatBrain->getBrain() << std::endl;
            std::cout << "hres-> " << getType() << std::endl;
        }
        virtual ~Cat();
};