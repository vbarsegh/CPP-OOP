#include "Dummy.hpp"


Dummy::Dummy() : ATarget("Target Practice Dummy")
{
}

Dummy* Dummy::clone() const
{
    Dummy* ob = new Dummy();
    return (ob);
}

Dummy::~Dummy()
{
}