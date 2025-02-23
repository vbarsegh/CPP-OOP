#pragma once
#include "ATarget.hpp"
class BrickWall : public ATarget
{
private:

public:
    BrickWall();
    virtual BrickWall* clone() const;
    ~BrickWall();
};