#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(NULL), _size(0)
{
	cout << "Array default ctor is called" << endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	cout << "Array ctor with param is called" << endl;
	_array = new(std::nothrow) T[_size];
	if (!_array)
		cout << "Can not allocate memeory!" << endl;
}

template <typename T>
Array<T>::Array(const Array& other) : _size(other._size)
{
	cout << "Array copy ctor is called" << endl;
	_array = new(std::nothrow) T[_size];
	if (!_array)
		cout << "Can not allocate memeory!" << endl;
	else
	{
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = other._array[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	cout << "Array operator= is called" << endl;
	if (this != &other)
	{
		delete[] _array;
		_array = new T[other._size];
		if (!_array)
			cout << "Can not allocate memeory!" << endl;
		else
		{
			for (unsigned int i = 0; i < other._size; i++)
				_array[i] = other._array[i];
			_size = other._size;
		}
	}
	return (*this);
	
}

template <typename T>
T& Array<T>::operator[](const unsigned int index)
{
	if (index >= _size)
		throw std::exception();
	return (_array[index]);
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (_size);
}

template <typename T>
Array<T>::~Array()
{
	cout << "Array dtor is called" << endl;
	delete[] _array;
}
