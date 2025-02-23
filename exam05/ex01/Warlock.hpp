#pragma once

#include <iostream>
#include <vector>
#include "ASpell.hpp"
class Warlock
{
private:
    std::vector<ASpell *> vec;
    std::string name;
    std::string title;
    Warlock();
    Warlock(const Warlock& other);
    Warlock& operator=(const Warlock& other);
public:
    const std::string& getName() const;
    const std::string& getTitle() const;
    void    setTitle(const std::string& title);
    Warlock(std::string  name, std::string title);
    ~Warlock();
    void introduce() const;
    void    learnSpell(ASpell* ob);
    void    forgetSpell(std::string name);
    void    launchSpell(std::string SpellName, ATarget& ob);
};