#include "DiamondTrap.hpp"


int main()
{
    DiamondTrap obj("ANRY");
    obj.attack("henry");
    std::cout << "ENERGY: " << obj.attackdamage() << std::endl;

    // std::cout << "\n\n";
    // obj.whoAmI();
    // std::cout << "\n\n";

    // obj.attack("hgfds");
    //ClapTrap *cp = new ScavTrap();

   // std::cout << cp->getName() << std::endl;
   // obj.guardGate();
   // delete cp;
    // ClapTrap *base = &obj;//copy ctor chi kanchvum

    // ScavTrap obj;
    // ClapTrap base = obj;//copy ctor a kachvum, hashvi arac vor jarangum ka, ete jarangum rac chlni compiloe-el chi lini
    

    // ScavTrap* obj = new ScavTrap();
    
    // obj->ClapTrap::attack("Adel");
    // delete obj;

//     ScavTrap obj;
//     ClapTrap *base = &obj;
//     base->attack("H");
//     std::cout << "ooo " << base->a;//uzele cuyc tam vor base-i obj-ov chem kara acancyal dasi memberin dimem bayc virtual ete lini attack-@ dra mej a-n karam ogtagorcem
}
