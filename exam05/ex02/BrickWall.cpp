#include "BrickWall.hpp"


BrickWall::BrickWall() : ATarget("Inconspicuous Red-brick Wall")
{
}

BrickWall* BrickWall::clone() const
{
    BrickWall* ob = new BrickWall();
    return (ob);
}

BrickWall::~BrickWall()
{
}