#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
	private:
		std::string type;
	public:
		// Weapon();
		Weapon(std::string type);
		const std::string& getType();
		void	setType(std::string new_type);//ete getType-@ veradardznuma const std::string&,chpiti private member type-@ lini const std::string type;?????che brats,chshtaca!!!
		~Weapon();
};

#endif