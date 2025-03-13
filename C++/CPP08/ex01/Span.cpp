#include "Span.hpp"

Span::Span() : _max_num_of_container(0), _current_elem_ind(0)
{
    cout << "Default ctor is called" << endl;
}

Span::Span(unsigned int N) : _max_num_of_container(N), _current_elem_ind(0)
{
    cout << "ctor with param is called" << endl;
}
// Span::Span(const Span& other)
// {
//     cout << "Copy ctor is called" << endl;
//     _vec = other._vec;
//     _max_num_of_container = other._max_num_of_container;
//     _current_elem_ind = other._current_elem_ind;
// }
//`````Что здесь происходит?
// 1)Сначала вызывается конструктор по умолчанию для _vec (std::vector<int>), который создает пустой вектор.
// Затем выполняется оператор присваивания _vec = other._vec;, который копирует все элементы other._vec в _vec.
// В итоге у нас два вызова конструктора:
// Конструктор по умолчанию (создает пустой std::vector<int>).
// Оператор присваивания, который копирует данные из other._vec.
// ✅ Если использовать initializer list, этого лишнего копирования не будет.
//2)Возможность исключений и неопределенного состояния
// Что может пойти не так?
// Если при копировании _vec = other._vec; произойдет исключение (например, нехватка памяти), то объект Span будет частично создан.
// Поля _max_num_of_container и _current_elem_ind могут оказаться неинициализированными или в некорректном состоянии.
// Если конструктор завершился с исключением, то деструктор может не вызваться, что может привести к утечке памяти.
// ✅ При использовании initializer list исключение выбрасывается раньше, до создания объекта, и объект вообще не создается.

Span::Span(const Span& other) : _vec(other._vec), _max_num_of_container(other._max_num_of_container), _current_elem_ind(other._current_elem_ind)
{
    cout << "Copy ctor is called" << endl;
}

Span& Span::operator=(const Span& other)
{
    cout << "Copy assignment is called" << endl;
    if (this != &other)
    {
        _vec = other._vec; 
        _max_num_of_container = other._max_num_of_container;
        _current_elem_ind = other._current_elem_ind;
    }
    return (*this);
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

unsigned int Span::shortestSpan()
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

unsigned int Span::longestSpan()
{
    if (_current_elem_ind <= 1)
        throw CanNotFindlongestSpan();
    std::sort(_vec.begin(), _vec.end());
    return (_vec[_vec.size() - 1] - _vec[0]);
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
