#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "default ctor is called" << std::endl;
    this->fixed_point_value = 100000000;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->fixed_point_value = value << this->fractional_bits;//<=>value * (1 << this->fractional_bits))
    // std::cout << "int ctor " << fixed_point_value << std::endl;
}

Fixed::Fixed(float	value)
{
    std::cout << "Float constructor called" << std::endl;
    long long temp = roundf(value * (1 << this->fractional_bits));
    if (temp > INT_MAX)
        temp = INT_MAX;
    else if (temp < INT_MIN)
        temp = INT_MIN;
    
    this->fixed_point_value = temp;//stugenq tenanq chishta???????
    // std::cout << "float ctor " << fixed_point_value << std::endl;

}

Fixed::Fixed(const Fixed& other) : fixed_point_value(other.fixed_point_value)
{
    std::cout << "copy ctor is called" << std::endl;
    // *this = other;//lav praktika chi
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "copy assignment is called" << std::endl;
    if (this == &other)
        return (*this);
    this->fixed_point_value = other.getRawBits();
    return (*this);
}

void Fixed::setRawBits( int const raw )
{
    // std::cout << "setRawBits is called" << std::endl;
    this->fixed_point_value = raw;
}
int Fixed::getRawBits( void ) const
{
    // std::cout << "getRawBits is called" << std::endl;
    return (this->fixed_point_value);
}

float Fixed::toFloat( void ) const
{
    return (static_cast<float>(this->fixed_point_value) / (1 << this->fractional_bits));
}

int Fixed::toInt( void ) const
{
    return (this->fixed_point_value >> this->fractional_bits);
}


Fixed::~Fixed()
{
    std::cout << "dtor is called" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return (os);
}

bool Fixed::operator>(const Fixed& other) const
{
    return (this->fixed_point_value > other.fixed_point_value);
}

bool Fixed::operator>=(const Fixed& other) const
{
    return (this->fixed_point_value >= other.fixed_point_value);
}

bool Fixed::operator<(const Fixed& other) const
{
    return (this->fixed_point_value < other.fixed_point_value);
}

bool Fixed::operator<=(const Fixed& other) const
{
    return (this->fixed_point_value <= other.fixed_point_value);
}

bool Fixed::operator==(const Fixed& other) const
{
    return (this->fixed_point_value == other.fixed_point_value);
}

bool Fixed::operator!=(const Fixed& other) const
{
    return (this->fixed_point_value != other.fixed_point_value);
}

Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed res(this->toFloat() + other.toFloat());

    // res.setRawBits(this->toFloat() + other.toFloat());
    return (res);
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed res(this->toFloat() - other.toFloat());

    // res.setRawBits(this->toFloat() - other.toFloat());
    return (res);
}

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed res(this->toFloat() * other.toFloat());

    // res.setRawBits(this->toFloat() * other.toFloat());
    // res.setRawBits(this->fixed_point_value * other.fixed_point_value);
    return (res);
}

Fixed Fixed::operator/(const Fixed& other) const
{
    // if (other.fixed_point_value == 0)
    // {
    //     std::cerr << "matem chgites" << std::endl;
    //     exit(1111);
    // }
    Fixed res(this->toFloat() / other.toFloat());

    // res.setRawBits(this->toFloat() / other.toFloat());
    return (res);
}

Fixed& Fixed::operator++()
{
    // float num = this->toFloat();
    // num++;
    // this->fixed_point_value = roundf(num * (1 << this->fractional_bits));
    this->fixed_point_value++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed   temp;

    temp = *this;
    // float num = this->toFloat();
    // num++;
    // this->fixed_point_value = roundf(num * (1 << this->fractional_bits));
    this->fixed_point_value++;
    return (temp);
}

Fixed& Fixed::operator--()
{
    float num = this->toFloat();
    num--;
    this->fixed_point_value = roundf(num * (1 << this->fractional_bits));
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed   temp;

    temp = *this;
    // float num = this->toFloat();
    // num--;
    // this->fixed_point_value = roundf(num * (1 << this->fractional_bits));
    this->fixed_point_value--;
    return (temp);
}

Fixed& Fixed::min(Fixed& f1, Fixed& f2)
{
    return (f1 < f2 ? f1 : f2);
}
Fixed& Fixed::min(const Fixed& f1, const Fixed& f2)
{
    return (Fixed::min(const_cast<Fixed&>(f1), const_cast<Fixed&>(f2)));
}

Fixed& Fixed::max(Fixed& f1, Fixed& f2)
{
    return (f1 > f2 ? f1 : f2);
}
Fixed& Fixed::max(const Fixed& f1, const Fixed& f2)
{
    return (Fixed::max(const_cast<Fixed&>(f1), const_cast<Fixed&>(f2)));
}