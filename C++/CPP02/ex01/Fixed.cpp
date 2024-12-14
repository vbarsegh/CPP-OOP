#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "default ctor is called" << std::endl;
    this->fixed_point_value = 0;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->fixed_point_value = value << this->fractional_bits;//<=>value * (1 << this->fractional_bits))
    std::cout << "int ctor " << fixed_point_value << std::endl;
}
//KAREVOR
// Используйте value << 3, если:

// Вы работаете с целыми числами.
// Вам нужна максимальная производительность.
// Используйте value * (1 << 3), если:

// Вы работаете с числами с плавающей точкой.
// Вам нужна поддержка дробной части.



// Операция	                 value << 3	                                   value * (1 << 3)
// Типы данных	         Только целые (int, unsigned).                	Целые и числа с плавающей точкой.
// Смысл	                 Сдвиг битов влево.                              	Умножение на 2^3=8
// Производительность	     Быстрее, особенно для целых типов.	         Немного медленнее из-за умножения.
// Точность	           Только целые числа, дроби теряются.	         Поддерживает дробные значения.


// Итог:
// Целые числа? Можно использовать и <<, и * (1 << 3), но << быстрее.
// Числа с плавающей точкой? Только * (1 << 3) подходит.
Fixed::Fixed(float	value)
{
    std::cout << "Float constructor called" << std::endl;
    this->fixed_point_value = roundf(value * (1 << this->fractional_bits));//roundf-i shnorhiv->Or. 44.6 = 45;  44.3 = 44;
    std::cout << "float ctor " << fixed_point_value << std::endl;

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
    // this->fixed_point_value = other.getRawBits();//inchi chenq anum other.fixed_point_value
    this->fixed_point_value = other.fixed_point_value;
   
    return (*this);
}

// void Fixed::setRawBits( int const raw )
// {
//     // std::cout << "setRawBits is called" << std::endl;
//     this->fixed_point_value = raw;
// }
// int Fixed::getRawBits( void ) const
// {
//     // std::cout << "getRawBits is called" << std::endl;
//     return (this->fixed_point_value);
// }

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

