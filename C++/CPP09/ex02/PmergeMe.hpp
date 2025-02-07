#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <limits>
#include <sstream>
using std::cout;
using std::endl;

template <typename Container>
class PmergeMe{
private:
    Container ctr;
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();
    void    fill_container(char** argv);
    void    print();
    void    sort();
};

#include "PmergeMe.tpp"