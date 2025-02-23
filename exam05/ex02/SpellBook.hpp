#pragma once
#include "ASpell.hpp"
#include <vector>
class SpellBook
{
private:
    std::vector<ASpell*> spells;
    SpellBook(const SpellBook& other);
    SpellBook& operator=(const SpellBook& other);
public:
    SpellBook();
    void learnSpell(ASpell* ob);
    void forgetSpell(std::string const &spellName);
    ASpell* createSpell(std::string const &spellName);
    ~SpellBook();
};