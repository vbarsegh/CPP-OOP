#pragma once
#include "ATarget.hpp"
#include <string>
class ASpell
{
private:
    ASpell();
    ASpell(const ASpell& other);
    ASpell& operator=(const ASpell& other);
protected:
    std::string name;
    std::string effects;
public:
    std::string getEffects() const;
    std::string getName() const;
    virtual ASpell* clone() const = 0;
    ASpell(std::string  name, std::string effects);
    void    launch(const ATarget& ob);
    virtual ~ASpell();
};