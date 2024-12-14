#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "default ctor is called" << std::endl;
    this->fixed_point_value = 0;
}

Fixed::Fixed(const Fixed& other) : fixed_point_value(other.fixed_point_value)
{
    std::cout << "copy ctor is called" << std::endl;
    // *this = other;//senc chenq ani ete unenq dinamic hishoxutyun,vortev *this = other-i ardyunqum kkanchvi op=,vori mej deep copy pti arvi,et iranic nerkayacnuma delete enq anum this-i sax membernery u nor taza new enq anum this-i hamar u grum orinak this->a = other.a e ayln, bayc xndiry nranuma vor seg kta op=-i mej,vortev hly this-i membernery chkan(zibil en)isk es dre free em anum!!!!!!
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
    std::cout << "setRawBits is called" << std::endl;
    this->fixed_point_value = raw;
}
int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits is called" << std::endl;
    return (this->fixed_point_value);
}

Fixed::~Fixed()
{
    std::cout << "dtor is called" << std::endl;
}