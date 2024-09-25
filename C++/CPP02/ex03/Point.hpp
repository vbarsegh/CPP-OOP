#pragma once

#include "Fixed.hpp"
#include <iostream>
#include <string>
#include <cmath>

class Point
{
private:
    Fixed const x;
    const Fixed y;//cuyc talu hamar,vor tarberutyun chka
public:
    Point();
    Point(const float fx, const float fy);
    Point(const Point& other);
    Point& operator=(const Point& other);
    const Fixed&   get_Fixed_y();
	const Fixed&   get_Fixed_x();
    ~Point();
};

