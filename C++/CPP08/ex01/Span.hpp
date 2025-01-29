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
    // Span(const Span& other);
    // Span& operator=(const Span& other);
    ~Span();
    void    addNumber(int);
    int get_vec_num(int i){return _vec[i];}
    long long shortestSpan();
    long long longestSpan();

    struct VectorAlreadyFull : public std::exception {const char* what() const throw();};
    struct VectorWillBeFull : public std::exception {const char* what() const throw();};
    struct CanNotFindshortestSpan : public std::exception {const char* what() const throw();};   
    struct CanNotFindlongestSpan : public std::exception {const char* what() const throw();};   
    
    template  <typename T>
    void    TaddNumber(typename T::iterator begin, typename T::iterator end);
};    

template  <typename T>
void    Span::TaddNumber(typename T::iterator begin, typename T::iterator end)
{
    cout << ",ds->"<<std::distance(begin, end) << endl;
    if (_current_elem_ind + std::distance(begin, end) >= _max_num_of_container)
        throw VectorWillBeFull();
    for (typename T::iterator it = begin; it != end; it++)//!= vochte <
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