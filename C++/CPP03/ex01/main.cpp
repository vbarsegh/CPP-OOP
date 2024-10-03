#include "ClapTrap.hpp"
#include "ScavTrap.hpp"


int main()
{

    // ScavTrap obj;
    // ClapTrap *base = &obj;//copy ctor chi kanchvum

    // ScavTrap obj;
    // ClapTrap base = obj;//copy ctor a kachvum, hashvi arac vor jarangum ka, ete jarangum rac chlni compiloe-el chi lini
    

    // ScavTrap* obj = new ScavTrap();
    
    // obj->ClapTrap::attack("Adel");
    // delete obj;


    ScavTrap obj("vrd");
    ClapTrap *base = &obj;
    base->attack("H");
    obj.attack("H");



    // ScavTrap obj2("barxudar");
    // ClapTrap *obj1 = &obj2;
	// std::cout << "hres = " << obj1->get_name() << std::endl;
	// std::cout << "hress = " << obj2.get_name() << std::endl;
	// std::cout << "hres int = " << obj1->get_int_member() << std::endl;
	// std::cout << "hress int = " << obj2.get_int_member() << std::endl;

	// ScavTrap obj2;
    // ClapTrap *obj1 = &obj2;
	// std::cout << "hres = " << obj1->get_name() << std::endl;
	// std::cout << "hress = " << obj2.get_name() << std::endl;

	

    // ClapTrap obj1("bldo");
	// ScavTrap obj2("esel voch bldo");
	// std::cout << "hres = " << obj1.get_name() << std::endl;
	// std::cout << "hress = " << obj2.get_name() << std::endl;
	// std::cout << "hres int = " << obj1.get_int_member() << std::endl;
	// std::cout << "hress int = " << obj2.get_int_member() << std::endl;

}

