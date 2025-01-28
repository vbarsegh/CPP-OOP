#pragma once

#include <iostream>
#include <vector>

template <typename T>
typename T::iterator easyfind(T& container, int eger)
{
    typename T::iterator it = std::find(container.begin(), container.end(), eger);
    if (it == container.end())
        throw std::out_of_range("Value not found in container");
    return (it);
}

