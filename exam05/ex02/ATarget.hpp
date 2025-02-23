#pragma once
#include <iostream>
class ASpell;
// #include "ASpell.hpp"

class ATarget
{
private:
    ATarget();
protected:
    std::string type;
    ATarget(const ATarget& other);
    ATarget& operator=(const ATarget& other);
public:
    const std::string& getType() const;
    virtual ATarget* clone() const = 0;
    ATarget(std::string  type);
    void    getHitBySpell(const ASpell& ob) const;
    virtual ~ATarget();
};