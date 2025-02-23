#pragma once
#include "ASpell.hpp"

class Fireball : public ASpell
{
private:

public:
    Fireball();
    virtual Fireball* clone() const;
    ~Fireball();
};