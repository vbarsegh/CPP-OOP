#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "default ctor is called" << std::endl;
    this->fixed_point_value = 0;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    // this->fixed_point_value = value << this->fractional_bits;//<=>value * (1 << this->fractional_bits))
    long long temp = value << this->fractional_bits;
    if (temp > INT_MAX)
        temp = INT_MAX;
    else if (temp < INT_MIN)
        temp = INT_MIN;
    this->fixed_point_value = temp;
}

Fixed::Fixed(float	value)
{
    // this->fixed_point_value = roundf(value * (1 << this->fractional_bits));//roundf-i shnorhiv->Or. 44.6 = 45;  44.3 = 44;
    std::cout << "Float constructor called" << std::endl;
    long long temp = roundf(value * (1 << this->fractional_bits));
    if (temp > INT_MAX)
        temp = INT_MAX;
    else if (temp < INT_MIN)
        temp = INT_MIN;
    this->fixed_point_value = temp;
}

Fixed::Fixed(const Fixed& other) : fixed_point_value(other.fixed_point_value)
{
    std::cout << "copy ctor is called" << std::endl;
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

/////////// 6 comparison operators: >, <, >=, <=, == and !=.///////////
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

///////e 4 arithmetic operators: +, -, *, and /.

//Для операторов, которые модифицируют текущий объект, используйте ClassName&. operator(+=,-=,*=,/=)bayc sranq chi pahanjvum overload anel
//Для операторов, которые создают новый объект, всегда используйте ClassName (по значению).operator(+,-,*,/) vorovhetev->
//SXAL OVERLOAD`
// ClassName& operator+(const ClassName& lhs, const ClassName& rhs) {
//     ClassName result; // Локальный объект
//     result.value = lhs.value + rhs.value;
//     return result; // Ошибка! Возвращаем ссылку на уничтоженный объект
// }kveradarcneinq jnjvox obyekti hascen,xi jnjvox,vortev lokal popoxakana ClassName result-@,isk lokalnery henc skopken prcav maqrvuma hishoxutyunic


Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed res(this->toFloat() + other.toFloat());//xi toFloat-ov?
    return (res);
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed res(this->toFloat() - other.toFloat());
    return (res);
}

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed res(this->toFloat() * other.toFloat());
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
    return (res);
}

//////
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

    temp = *this;//op=-i kanch=>temp-@ u this-@ es toxic nerqev 2tarber hishoxutyunnerum nuyn "parunakutyuny" unecox obyektner en
    this->fixed_point_value++;//this->value-n mecacnum enq 1ov
    return (temp);//veradarcnum hin vijakov obyekty(++ chexacy),vortev post incrementy hin arjeqova veragrvum nor ++a linum
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
    this->fixed_point_value--;
    return (temp);
}

const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2)
{
    return (f1 < f2 ? f1 : f2);
    // return (Fixed::min(const_cast<Fixed&>(f1), const_cast<Fixed&>(f2)));
}

Fixed& Fixed::min(Fixed& f1, Fixed& f2)
{
    const Fixed& f1_copy = static_cast<const Fixed&>(f1);
    const Fixed& f2_copy = static_cast<const Fixed&>(f2);
    Fixed& res = const_cast<Fixed&>(Fixed::min(f1_copy, f2_copy));
    return (res);
    // return (const_cast<Fixed&>(Fixed::min(static_cast<const Fixed&>(f1), static_cast<const Fixed&>(f2))));
}

Fixed& Fixed::max(Fixed& f1, Fixed& f2)
{
    return (const_cast<Fixed&>(Fixed::max(static_cast<const Fixed&>(f1), static_cast<const Fixed&>(f2))));
}
const Fixed& Fixed::max(const Fixed& f1, const Fixed& f2)
{
    return (f1 > f2 ? f1 : f2);
}
