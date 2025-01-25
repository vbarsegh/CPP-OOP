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
// Если методы шаблонного класса определены в .cpp файле, они не будут видны при использовании шаблона в других файлах, поскольку .cpp файл компилируется отдельно. Поэтому шаблонные методы либо:
// 1)Определяются внутри заголовочного файла (*.hpp) сразу после объявления класса.
// 2)Переносятся в специальный файл (*.tpp), который подключается внутри заголовочного файла.

// .tpp	Файл реализации методов шаблонного класса.