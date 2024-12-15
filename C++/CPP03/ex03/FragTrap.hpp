#pragma once
#include "ClapTrap.hpp"
#include <iostream>
#include <string>

class FragTrap : virtual public ClapTrap
{
    // public:
    //     const int a;
    public:
        FragTrap(int);
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap& other);
        FragTrap& operator=(const FragTrap& other);
        void highFivesGuys(void);
        virtual ~FragTrap();
};

