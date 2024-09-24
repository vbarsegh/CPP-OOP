#include "Point.hpp"

Point::Point() : x(0) , y(0)
{
    std::cout << "Default ctor is called" << std::endl;  
}

Point::Point(const float fx, const float fy) : x(fx), y(fy)
{
    std::cout << "Ctor with params is called" << std::endl;
}


Point::Point(const Point& other) : x(other.x), y(other.y)
{
    std::cout << "Copy ctor is called" << std::endl;
    // this->x = other.x;
    // this->y = other.y;
}

Point& Point::operator=(const Point& other)
{
    // if (*this != other)
    // {
    //     this->x = other.x;
    //     this->y = other.y;
    // }
    (void)other;
    return (*this);
}


Point::~Point()
{
    std::cout << "dtor is called" << std::endl;
}