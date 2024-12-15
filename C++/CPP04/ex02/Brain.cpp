#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default ctor is called" << std::endl;
}

Brain::Brain(const Brain& other)
{
    std::cout << "Brain copy ctor is called" << std::endl;
    for (int i = 0; i < 100; i++)
    {
        this->ideas[i] = other.ideas[i];
    }
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Brain op+ is called" << std::endl;
    if (this == &other)
        return (*this);
    for (int i = 0; i < 100; i++)
    {
        this->ideas[i] = other.ideas[i];
    }
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain dtor is called" << std::endl;
}