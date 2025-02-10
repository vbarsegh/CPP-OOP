#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <limits>
#include <sstream>
#include <ctime>
using std::cout;
using std::endl;

class PmergeMe{
private:
    std::deque<int> deq;
    std::vector<int> vec;
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();
    template <typename Container>
    void    fill_container(char** argv, Container& ctr);
    void    print();
    size_t len(std::string str, char c);
    char* trim(char* str);
    void    sort(char** argv);
    template <typename Container>
    size_t  get_ctr_size(Container ctr);
    // double calculate_time();   
};
