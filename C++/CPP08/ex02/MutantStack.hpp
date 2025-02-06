#pragma once

#include <iostream>
// #include <vector>
#include <stack>
using std::cout;
using std::endl;


template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
    typedef typename std::stack<T, Container>::container_type::iterator iterator;
    typedef typename std::stack<T, Container>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T, Container>::container_type::const_iterator const_iterator;
    typedef typename std::stack<T, Container>::container_type::const_reverse_iterator const_reverse_iterator;
    MutantStack();
    MutantStack(const MutantStack& other);
    MutantStack& operator=(const MutantStack& other);
    virtual ~MutantStack();
    iterator begin();
    iterator end();
    reverse_iterator rbegin();
    reverse_iterator rend();
    const_iterator cbegin() const;
    const_iterator cend() const ;
    const_reverse_iterator crbegin() const;
    const_reverse_iterator crend() const;
};

#include "MutantStack.tpp"
// template <class T, class Container = std::deque<T>>
// class stack {
// protected:
//     Container c; // Контейнер, хранящий элементы стека
// public:
//     // --- Конструкторы ---
//     stack() : c() {} // Конструктор по умолчанию
//     explicit stack(const Container& cont) : c(cont) {} // Конструктор от контейнера

//     // --- Основные методы ---
//     void push(const T& value) { c.push_back(value); }
//     void pop() { c.pop_back(); }
//     T& top() { return c.back(); }
//     const T& top() const { return c.back(); }
//     size_t size() const { return c.size(); }
//     bool empty() const { return c.empty(); }

//     // --- Операторы сравнения ---
//     bool operator==(const stack& other) const { return c == other.c; }
//     bool operator!=(const stack& other) const { return c != other.c; }
//     bool operator<(const stack& other) const { return c < other.c; }
//     bool operator<=(const stack& other) const { return c <= other.c; }
//     bool operator>(const stack& other) const { return c > other.c; }
//     bool operator>=(const stack& other) const { return c >= other.c; }
// };
