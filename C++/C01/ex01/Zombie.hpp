#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>
#include <string>

class Zombie
{
private:
    std::string name;
public:
    Zombie();//ete sa chavelacnenq
    Zombie(std::string name);
	void announce( void );
    ~Zombie();
};

#endif 