#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include "Weapon.hpp"

class HumanA
{
	private:
        Weapon&  wp1;
		std::string name;
	public:
		HumanA(std::string name, Weapon& club);
		void    attack();
		~HumanA();
};

#endif