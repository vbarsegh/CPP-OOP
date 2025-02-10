#include "PmergeMe.hpp"


PmergeMe::PmergeMe()
{
    // cout << "PmergeMe default ctor is called" << endl;
}


PmergeMe::PmergeMe(const PmergeMe& other) : deq(other.deq), vec(other.vec)
{
    // cout << "PmergeMe copy ctor is called" << endl;
}


PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        // cout << "PmergeMe operator= is called" << endl;
        vec = other.vec;
        deq = other.deq;
    }
    return (*this);
}


PmergeMe::~PmergeMe()
{
    // cout << "PmergeMe dtor is called" << endl;
}

size_t PmergeMe::len(std::string str, char c)
{
    size_t count = 0;
  for (size_t i = 0; i < str.length(); i++) {
        if (str[i] == c)
            count++;
    }
    return (count);
}


char* PmergeMe::trim(char* str) {
    while (*str == ' ') str++; // Убираем пробелы в начале

    char* end = str + std::strlen(str) - 1;
    while (end > str && *end == ' ') end--; // Убираем пробелы в конце

    *(end + 1) = '\0'; // Завершаем строку
    return str;
}

template <typename Container>
void    PmergeMe::fill_container(char** argv, Container& ctr)
{
    for(size_t i = 1; argv[i]; ++i)
    {
        std::stringstream ss(argv[i]);
        std::string str = ss.str();
        long long elem;
        if (str.find_first_not_of(" +0123456789") != std::string::npos || str.size() > 10)
			throw std::runtime_error("Invaliiiid unput");
        str = trim(argv[i]);
        if (str.find('+') == std::string::npos
            || (str.find('+') == 0 && str.find('+') != std::string::npos && len(str, '+') == 1 && str.find(' ') == std::string::npos))
        {
            ss >> elem;
            if (elem > INT_MAX)
                throw std::runtime_error("elem higher than INT_MAX");
            ctr.push_back(elem);
        }
		else
            throw std::runtime_error("+ in invalid position or + is not 1");
    }
}


void	PmergeMe::print()
{
	for(size_t i = 0; i < vec.size(); ++i)
		cout << vec[i] << " ";
    cout << endl;
}


template <typename Container>
Container binary_search(Container big, Container small)
{
    size_t i = 1;//2^0
    while (!small.empty())
    {
        if (i >= small.size())
            i *= 0;
        typename Container::iterator middle;
		typename Container::iterator left = big.begin();
        typename Container::iterator right = big.end() - 1;
		while (left < right)
        {
			middle = left + std::distance(left, right) / 2;
            if (small[i] <= *middle)
                right = middle;
			else
                left = middle + 1;
        }
		big.insert(left, small[i]);
        small.erase(small.begin() + i);
        i *= 2;
    }
    return big;
}

template <typename Container>
Container rec(Container curr)
{
	Container big;
	Container small;
	if (curr.size() == 1)
		return curr;
	for (size_t i = 0; i < curr.size(); i+=2)
	{
		if (i == curr.size() - 1)
			big.push_back(curr[i]);
		else if (curr[i] > curr[i + 1])
		{			
			big.push_back(curr[i]);
			small.push_back(curr[i + 1]);
		}
		else
		{			
			big.push_back(curr[i + 1]);
			small.push_back(curr[i]);
		}
	}
	return binary_search(rec(big), small);
}


void PmergeMe::sort(char** argv)
{
        fill_container(argv, deq);
        fill_container(argv, vec);
        cout << "Before:  " ;
        print();
        // double time_vec = vec.calculate_time();
        clock_t start_vec = clock();
        vec = rec(vec);
        clock_t end_vec = clock(); 
        // double time_deq = deq.calculate_time();
        clock_t start_deq = clock();
        deq = rec(deq);
        clock_t end_deq = clock(); 
        
        cout << "After:   ";
        print();
        cout << "Time to process a range of "<< get_ctr_size(vec) <<  " elements with std::vector : " << (double)(end_vec - start_vec) / CLOCKS_PER_SEC * 10 << " us" << endl;
        cout << "Time to process a range of "<< get_ctr_size(deq) <<  " elements with std::deque  : " << (double)(end_deq - start_deq) / CLOCKS_PER_SEC * 10 << " us" << endl;
}

template <typename Container>
size_t  PmergeMe::get_ctr_size(Container ctr)
{
    return (ctr.size());
}


// double PmergeMe::calculate_time()
// {
//     clock_t start_vec = clock();
//     sort();
//     clock_t end_vec = clock(); 
//     return ((double)(end_vec - start_vec) / CLOCKS_PER_SEC * 10);
// }