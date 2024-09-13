#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main()
{
	std::string name_z;
    int N = 3;
    // std::cout << "N = ";
    // std::cin >> N;
	getline(std::cin, name_z);
    Zombie  *zombie;

    
	zombie = zombieHorde(N, name_z);
    for (int i = 0; i < N; i++)
    {
        zombie[i].announce();
    }
	delete [] zombie;

}