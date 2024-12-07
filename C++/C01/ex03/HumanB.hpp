#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

// #include "Weapon.hpp"
#include "HumanA.hpp"

class HumanB
{
	private:
        Weapon*  wp1;
		std::string name;
	public:
		HumanB(std::string name);
		void    attack();
        void    setWeapon(Weapon& club);    

		~HumanB();
};

#endif