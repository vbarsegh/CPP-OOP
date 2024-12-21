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
        void    sett(std::string ideas){this->CatBrain->ideas[0] = ideas;}
        void    gett()
        {
            std::cout << "cat1-iny-> " << CatBrain->ideas[0] << std::endl;
            std::cout << "hascen-> " << &CatBrain->ideas[0] << std::endl;

        }
        virtual ~Cat();
};