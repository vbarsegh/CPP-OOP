#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *zombies;
// (void)name;
	zombies = new Zombie[N];//esi cher stacvi
	for (int i = 0; i < N; i++)
    {
		std::cout << "hres "<<std::endl;
	    zombies[i] = Zombie(name);//chem jokum xia stexcvum u henc hajord toxum destroy ylnum ,scopic dus galuc haskanalia (funkciayi), bayc senc che,Agvaaaaan
    }
	return (zombies);
}