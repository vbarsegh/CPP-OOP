#include "Fwoosh.hpp"


Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed")
{
}

Fwoosh* Fwoosh::clone() const
{
    Fwoosh* ob = new Fwoosh();
    return (ob);
}

Fwoosh::~Fwoosh()
{
 
}