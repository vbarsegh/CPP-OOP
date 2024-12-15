#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
    AMateria* learnedMaterias[4];
public:
    MateriaSource();
    MateriaSource(const MateriaSource& other);
    MateriaSource& operator=(const MateriaSource& other);
    virtual void learnMateria(AMateria*);
    virtual AMateria* createMateria(std::string const & type);
    ~MateriaSource();
};
