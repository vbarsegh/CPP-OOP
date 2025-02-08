#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <limits>
#include <sstream>
#include <ctime>
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
    size_t len(std::string str, char c);
    char* trim(char* str);
    void    sort();
    size_t  get_ctr_size();
    double calculate_time();   
};

#include "PmergeMe.tpp"