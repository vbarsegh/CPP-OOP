#include "SpellBook.hpp"

SpellBook::SpellBook()
{

}

void SpellBook::learnSpell(ASpell* ob)
{
    int i = 0;
    while (i < spells.size())
    {
        if (spells[i]->getName() == ob->getName())
            return ;
        i++;
    }
    spells.push_back(ob->clone());
}

void SpellBook::forgetSpell(std::string const &spellName)
{
    int i = 0;
    while (i < spells.size())
    {
        if (spells[i]->getName() == spellName)
        {
            delete spells[i];
            spells.erase(spells.begin() + i);
            return ;
        }
        i++;
    }
}

ASpell* SpellBook::createSpell(std::string const &spellName)
{
    int i = 0;
    while (i < spells.size())
    {
        if (spells[i]->getName() == spellName)
        {
            return spells[i]->clone();
        }
        i++;
    }
    return (NULL);
}



SpellBook::~SpellBook()
{
    int i = 0;
    while (i < spells.size())
    {
        delete  spells[i];
        i++;
    }
}
