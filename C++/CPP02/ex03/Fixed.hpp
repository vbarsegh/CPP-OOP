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
    int getRawBits( void ) const;
	void setRawBits( int const raw );
    float toFloat( void ) const;
	int toInt( void ) const;
    bool operator>(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;
    Fixed& operator++();//Префиксный инкремент
	Fixed operator++(int);// Постфиксный инкремент
	Fixed& operator--();// Префиксный декремент
	Fixed operator--(int);// Постфиксный декремент
	static Fixed& min(Fixed& f1, Fixed& f2);
	static Fixed& min(const Fixed& f1, const Fixed& f2);
	static Fixed& max(Fixed& f1, Fixed& f2);
	static Fixed& max(const Fixed& f1, const Fixed& f2);




    ~Fixed();
};

std::ostream& operator<<(std::ostream& os, const Fixed &fixed);
