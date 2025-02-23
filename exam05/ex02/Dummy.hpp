#pragma once
#include "ATarget.hpp"
class Dummy : public ATarget
{
private:

public:
    Dummy();
    virtual Dummy* clone() const;
    ~Dummy();
};