#pragma once 

template <typename T>
void    swap(T& a, T& b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template <typename T> T& min(T& first, T& second);//prototype

template <typename T> T& max(T& first, T& second);

template <typename T>
T& min(T& first, T& second)//realization
{
    return (first < second ? first : second);
}

template <typename T>
T& max(T& first, T& second)//realization
{
    return (first > second ? first : second);
}