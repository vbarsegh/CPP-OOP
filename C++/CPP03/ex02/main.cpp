#include "ClapTrap.hpp"
#include "FragTrap.hpp"


int main()
{
    //ScavTrap obj("asf");
    ClapTrap *cp = new FragTrap();

    std::cout << cp->getName() << std::endl;
    delete cp;
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
