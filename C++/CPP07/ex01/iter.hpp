#pragma once

#include <typeinfo>
#include <iostream>

template <typename T>
void    iter(const T* arr, size_t len, void (*func)(const T&))
{
	if (!arr)
		return ;
	for (size_t i = 0; i < len; i++)
		func(arr[i]);
	std::cout << "Type of T " << typeid(T).name() << std::endl;
}

template <typename T>
void	func(const T& argument)
{
	std::cout << "current argument is " << argument << std::endl;
}