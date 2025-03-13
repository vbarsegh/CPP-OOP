#pragma once

#include <iostream>
#include <vector>
using std::cout;
using std::endl;

class Span
{
private:
    std::vector<int> _vec;
    unsigned int _max_num_of_container;
    unsigned int _current_elem_ind;
public:
    Span();
    Span(const unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();
    void    addNumber(int);
    int get_vec_num(int i){return _vec[i];}
    unsigned int shortestSpan();
    unsigned int longestSpan();

    struct VectorAlreadyFull : public std::exception {const char* what() const throw();};
    struct VectorWillBeFull : public std::exception {const char* what() const throw();};
    struct CanNotFindshortestSpan : public std::exception {const char* what() const throw();};   
    struct CanNotFindlongestSpan : public std::exception {const char* what() const throw();};   
    
    // template  <typename T>
    // void    TaddNumber(typename T::iterator begin, typename T::iterator end);

    template <typename Iterator>
    void    TaddNumber(Iterator begin, Iterator end);
};    


template <typename Iterator>
void Span::TaddNumber(Iterator begin, Iterator end)
{
    if (_current_elem_ind + std::distance(begin, end) >= _max_num_of_container)
        throw VectorWillBeFull();
    for (Iterator it = begin; it != end; it++)//!= vochte <
    {
        try{
        addNumber(*it);
        }
        catch(const std::exception& e)
        {
            cout << e.what() << endl;
        }
    }
}

// то Iterator не зависит от контейнера и может быть любым типом, поддерживающим итерацию (std::vector<int>::iterator, std::list<int>::iterator, int*).
// Этот вариант работает и с массивами, и с контейнерами.



// Iterator — это не контейнер, а прямо тип итератора.
// Это может быть любой итератор: std::vector<int>::iterator, std::list<int>::iterator, int* (указатель на массив).
// Позволяет передавать массивы, потому что int* (указатель) тоже является итератором.


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// template  <typename T>
// void    Span::TaddNumber(typename T::iterator begin, typename T::iterator end)
// {
//     cout << ",ds->"<<std::distance(begin, end) << endl;
//     if (_current_elem_ind + std::distance(begin, end) >= _max_num_of_container)
//         throw VectorWillBeFull();
//     for (typename T::iterator it = begin; it != end; it++)//!= vochte <
//     {
//         try{
//         addNumber(*it);
//         }
//         catch(const std::exception& e)
//         {
//             cout << e.what() << endl;
//         }
//     }
// }
//T — это тип контейнера (например, std::vector<int> или std::list<int>).
// typename T::iterator означает, что begin и end должны быть итераторами, принадлежащими именно этому контейнеру T.

// запись typename T::iterator означает, что T — это какой-то класс или структура, внутри которого есть тип iterator.`

// Такой вариант не поддерживает обычные массивы int arr[5], потому что у int[5] нет iterator.
// Он требует, чтобы переданный контейнер имел тип T, а итераторы были именно T::iterator.

// std::vector<int> vec = {1, 2, 3, 4, 5};
// sp.TaddNumber(vec.begin(), vec.end());  // Работает

// int arr[] = {1, 2, 3, 4, 5};
// sp.TaddNumber(arr, arr + 5);  // Ошибка! У int[5] нет T::iterator