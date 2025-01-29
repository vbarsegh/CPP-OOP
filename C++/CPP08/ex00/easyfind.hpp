#pragma once

#include <iostream>
#include <vector>

template <typename T>
typename T::iterator easyfind(T& container, int eger)
{
    typename T::iterator it = std::find(container.begin(), container.end(), eger);
    if (it == container.end())
        throw std::out_of_range("Value not found in container");
    // (*it) = 100;
    // std::cout << *(it);
    return (it);
}

template <typename T>
typename T::const_iterator easyfind(const T& container, int eger)
{
    typename T::const_iterator it = std::find(container.begin(), container.end(), eger);
    if (it == container.end())
        throw std::out_of_range("Value not found in container");
    // it++;
    // std::cout << *(it);
    return (it);
}