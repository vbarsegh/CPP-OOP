#pragma once
#include "ASpell.hpp"
class Fwoosh : public ASpell
{
private:

public:
    Fwoosh();
    virtual Fwoosh* clone() const;
    ~Fwoosh();
};