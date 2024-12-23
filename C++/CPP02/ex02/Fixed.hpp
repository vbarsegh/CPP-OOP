#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include <climits>

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
    int getRawBits( void ) const;
	void setRawBits( int const raw );
    float toFloat( void ) const;
	int toInt( void ) const;
    bool operator>(const Fixed& other) const;//sranq kochvum en hamematman operatorner u veradarcnum en true or false=> bool
    bool operator>=(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;//////
    const Fixed operator+(const Fixed& other) const;//tvabanakan operatorner
    const Fixed operator-(const Fixed& other) const;
    const Fixed operator*(const Fixed& other) const;
    const Fixed operator/(const Fixed& other) const;
	const Fixed operator++(int);
    const Fixed& operator++();
	const Fixed& operator--();
	const Fixed operator--(int);// Постфиксный декремент
	static Fixed& min(Fixed& f1, Fixed& f2);
	static const Fixed& min(const Fixed& f1, const Fixed& f2);
	static Fixed& max(Fixed& f1, Fixed& f2);
	static const Fixed& max(const Fixed& f1, const Fixed& f2);
    ~Fixed();
};

std::ostream& operator<<(std::ostream& os, const Fixed &fixed);
