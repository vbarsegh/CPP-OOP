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


//Неоптимальная работа с operator--():
//Использование промежуточного преобразования в operator--() (через toFloat()) избыточно и потенциально менее эффективно. Если fixed_point_value — это целочисленное представление, декремент можно делать напрямую:
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
    std::cout <<"hmm\n";
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






//zut texekutyun
// Нет, с помощью static_cast вы не можете добавить const к переменной. Однако, можно создать копию переменной с квалификатором const. Вот как это работает:

// Объяснение:
// static_cast позволяет конвертировать типы, но не добавляет const к самой переменной. Если вам нужно работать с const-копией, используйте следующую конструкцию:


// int a = 42;
// const int b = static_cast<const int>(a); // Создается `const`-копия
//a — это неконстантная переменная, и static_cast не меняет её квалификатор const. Чтобы поработать с a как с const, можно использовать ссылку на const:

// const int& constRef = static_cast<const int&>(a);
// Теперь constRef — это константная ссылка на a. Через эту ссылку вы не сможете модифицировать a, хотя сама переменная остаётся неконстантной.


// CONST_CAST
//const_cast может удалять или добавлять const к ссылкам и указателям, но не к самим переменным.
//Основное предназначение const_cast — убрать const, чтобы работать с функциями, которые не поддерживают константные данные

//Удаление const: Вы можете использовать const_cast для получения неконстантной ссылки или указателя из константного:

// const int a = 42;
// int& ref = const_cast<int&>(a); // Убираем const
// ref = 50; // ОПАСНО: модифицируем объект, который был определён как const
// ⚠️ Это undefined behavior (UB), если вы изменяете переменную, которая была определена как const. Используйте это только с уверенностью, что объект был неконстантным изначально.


//Константная ссылка (например, const int&) может быть привязана к неконстантной переменной. Это одна из ключевых особенностей C++, позволяющая безопасно ограничить изменение переменной через данную ссылку.
//int a = 42;
// const int& constRef = a; // Привязываем const ссылку к неконстантной переменной
// Переменная a остаётся неконстантной, и вы можете изменять её напрямую:


// a = 50; // ОК
// Однако через constRef вы не можете изменить a, потому что ссылка объявлена как const:

// cpp
// Копировать код
// constRef = 60; // Ошибка компиляции!
// Таким образом, constRef предоставляет доступ только для чтения к a, но не меняет саму природу переменной a.


//Важное различие: const int* a vs int* const a
// Если const стоит после *, это делает указатель неизменным, а не значение:

// int* const a = &x; // Указатель неизменен, но значение можно менять
// *a = 15;           // ОК
// a = &y;            // Ошибка: нельзя переназначить указатель