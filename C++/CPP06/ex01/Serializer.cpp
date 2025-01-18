#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Serializer default ctor is called" << std::endl;
}

Serializer::Serializer(const Serializer& other)
{
	std::cout << "Serializer copy ctor is called" << std::endl;
	*this = other;
}

Serializer& Serializer::operator=(const Serializer& other)
{
	if (this != &other)
    {
        std::cout << "Serializer operator= is called" << std::endl;
    }
    return (*this);
}

uintptr_t Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data*>(raw));
}



Serializer::~Serializer()
{
	std::cout << "Serializer dtor is called" << std::endl;
}