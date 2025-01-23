#pragma once

#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class Array
{
private:
    T *_array;
	unsigned int _size;
public:
    Array(unsigned int n);
	//////Orthodox
    Array();
	Array(const Array& other);
	Array& operator=(const Array& other);
    ~Array();
	/////////
	T& operator[](const unsigned int index);
	unsigned int size() const;
	struct IndexOutOfRange : public std::exception
	{
		const char* what() const throw();
	};
};

#include "Array.tpp"