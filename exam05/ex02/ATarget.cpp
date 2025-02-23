#include "ATarget.hpp"
#include "ASpell.hpp"
void    ATarget::getHitBySpell(const ASpell& ob) const
{
    std::cout << type << " has been " << ob.getEffects() << "!" << std::endl;
}

ATarget::ATarget(std::string  type)
{
    this->type = type;
}
const std::string& ATarget::getType() const
{
    return type;
}

ATarget::~ATarget()
{
}