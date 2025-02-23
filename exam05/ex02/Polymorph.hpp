#pragma once

#include "ASpell.hpp"

class Polymorph : public ASpell
{
private:

public:
    Polymorph();
    virtual Polymorph* clone() const;
    ~Polymorph();
};