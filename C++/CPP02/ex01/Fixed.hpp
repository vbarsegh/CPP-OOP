#pragma once

#include <iostream>
#include <string>
#include <cmath>


class Fixed
{
private:
    int					fixed_point_value;
	static const int	fractional_bits = 8; 
public:
    Fixed();
    Fixed(const int value);
    Fixed(float value);
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
    // int getRawBits( void ) const;
	// void setRawBits( int const raw );
    float toFloat( void ) const;
	int toInt( void ) const;
    ~Fixed();
};

std::ostream& operator<<(std::ostream& os, const Fixed &fixed);
