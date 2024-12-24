#pragma once

#include "Animal.hpp"
#include <iostream>
#include <string>

class Brain
{
        std::string ideas[100];
    public:
        Brain();
        Brain(const Brain& other);
        Brain& operator=(const Brain& other);
        ~Brain();
        void    setBrain(std::string& ideas){this->ideas[0] = ideas;}
        std::string    getBrain(){return ideas[0];}
};

