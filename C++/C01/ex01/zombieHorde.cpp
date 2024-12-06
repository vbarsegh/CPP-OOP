#include "Zombie.hpp"
#include <sstream> //

std::string intToString(int number) {
    std::ostringstream oss; // Создаем поток
    oss << number;          // Записываем число в поток
    return oss.str();        // Получаем строку из потока
}

// Zombie* zombieHorde( int N, std::string name )
// {
// 	Zombie* z = new Zombie[N];

// 	int i;
// 	for (i = 0; i < N; i++)
// 		z[i] = Zombie(name + std::to_string(i));
// 	return (z);
//}//senc er minch 06.12

Zombie* zombieHorde( int N, std::string name )
{
	Zombie* z = new Zombie[N];

	int i;
	for (i = 0; i < N; i++)
		z[i].set_name(name + intToString(i));
	return (z);
}