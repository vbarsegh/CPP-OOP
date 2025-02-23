#include "ASpell.hpp"

ASpell::ASpell(std::string  name, std::string effects)
{
    this->name = name;
    this->effects = effects;
}

std::string ASpell::getEffects() const
{
    return effects;
}

std::string ASpell::getName() const
{
    return name;
}

void    ASpell::launch(const ATarget& ob)
{
    ob.getHitBySpell(*this);
}

ASpell::~ASpell()
{
}