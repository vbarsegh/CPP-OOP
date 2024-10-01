#include "ClapTrap.hpp"
#include "ScavTrap.hpp"


int main()
{
    // Child o;
    // Base * ptr = &o;

    // ptr->y = 7;

    // ScavTrap obj;
    // ClapTrap *base = &obj;//copy ctor chi kanchvum

    // ScavTrap obj;
    // ClapTrap base = obj;//copy ctor a kachvum, hashvi arac vor jarangum ka, ete jarangum rac chlni compiloe-el chi lini
    

    // ScavTrap* obj = new ScavTrap();
    
    // obj->ClapTrap::attack("Adel");
    // delete obj;
    ScavTrap obj;
    ClapTrap *base = &obj;
    base->attack("H");
}
