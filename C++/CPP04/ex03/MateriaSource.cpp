#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		learnedMaterias[i] = NULL;
    std::cout << "MateriaSource ctor is called" << std::endl;
}
MateriaSource::MateriaSource(const MateriaSource& other)
{
    std::cout << "MateriaSource copy ctor is called" << std::endl;
	for (int i = 0; i < 4; i++)
		learnedMaterias[i] = other.learnedMaterias[i]->clone();	
}

MateriaSource &MateriaSource::operator=(const MateriaSource& other)
{
    std::cout << "Charachter copy assignment is called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			delete learnedMaterias[i];
			learnedMaterias[i] = other.learnedMaterias[i]->clone();
		}
	}
	return (*this);
}
void MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (learnedMaterias[i] == m)
		{
			std::cout << "already have this AMateria" << std::endl;
			return ;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (learnedMaterias[i] == NULL)
		{
			learnedMaterias[i] = m;
			std::cout << "learnMateria is called" << std::endl;
			return ;
		}
	}
	std::cout << "dont have any free learnedMaterias" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	std::cout << "createMateria is called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (learnedMaterias[i] != NULL)
		{
			if (learnedMaterias[i]->getType() == type)
			{
				return (learnedMaterias[i]->clone());
			}
		}
	}
	std::cout << "The type is unknown." << std::endl;
	return (NULL);
}

MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource dtor is called" << std::endl;
	for (int i = 0; i < 4; i++)
		delete learnedMaterias[i];
}