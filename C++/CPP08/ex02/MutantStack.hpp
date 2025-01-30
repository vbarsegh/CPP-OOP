#pragma once

#include <iostream>
// #include <vector>
using std::cout;
using std::endl;

class MutantStack : public std::stack<T>
{
private:

public:
    MutantStack();
    MutantStack(const MutantStack& other);
    MutantStack& operator=(const MutantStack& other);
    ~MutantStack();

};
