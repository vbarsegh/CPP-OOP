#include "MateriaSource.hpp"

void MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (learnedMaterias[i] == m)
			return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (learnedMaterias[i] == NULL)
		{
			learnedMaterias[i] = m;
			break ;
		}
	}
}

AMateria* MateriaSoure::createMateria(std::string const & type)
{
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
	return (NULL);
}
