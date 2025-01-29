#include "Span.hpp"

Span::Span() : _max_num_of_container(0), _current_elem_ind(0)
{
    cout << "Default ctor is called" << endl;
}

Span::Span(unsigned int N) : _max_num_of_container(N), _current_elem_ind(0)
{
    cout << "ctor with param is called" << endl;
}

Span::~Span()
{
    cout << "dtor is called" << endl;
}

void    Span::addNumber(int num)
{
    if (_current_elem_ind >= _max_num_of_container)
        throw VectorAlreadyFull();
    _vec.push_back(num);
    cout << num << " has been added" << endl;
    _current_elem_ind++;
}

long long Span::shortestSpan()
{
    if (_current_elem_ind <= 1)
        throw CanNotFindshortestSpan();
    std::sort(_vec.begin(), _vec.end());
    long long shortestspan = _vec[1] - _vec[0];
    for (size_t i = 2; i < _vec.size(); i++)
    {
        if ((_vec[i] - _vec[i - 1]) < shortestspan)
            shortestspan = _vec[i] - _vec[i - 1];
    }
    return (shortestspan);
}

long long Span::longestSpan()
{
    if (_current_elem_ind <= 1)
        throw CanNotFindlongestSpan();
    std::sort(_vec.begin(), _vec.end());
    long long longestspan = _vec[_vec.size() - 1] - _vec[0];
    // for (size_t i = 2; i < _vec.size(); i++)
    // {
    //     if ((_vec[i] - _vec[i - 1]) > longestspan)
    //         longestspan = _vec[i] - _vec[i - 1];
    // }
    return (longestspan);
}

const char* Span::VectorAlreadyFull::what() const throw()
{
    return ("Vector is already full");
}
const char* Span::VectorWillBeFull::what() const throw()
{
    return ("Vector will be full if I do this implementacia:)");
}

const char* Span::CanNotFindshortestSpan::what() const throw()
{
    return ("Can not find shortestSpan");
}
const char* Span::CanNotFindlongestSpan::what() const throw()
{
    return ("Vector will be full if I do this implementacia:)");
}