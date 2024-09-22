#pragma once

#include <iostream>
#include <string>

class Fixed
{
private:
    int					fixed_point_value;
	static const int	fractional_bits = 8; 
public:
    Fixed();
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
    ~Fixed();
};
