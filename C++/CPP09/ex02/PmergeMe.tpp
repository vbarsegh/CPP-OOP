#include "PmergeMe.hpp"

template <typename Container>
PmergeMe<Container>::PmergeMe()
{
    cout << "PmergeMe default ctor is called" << endl;
}

template <typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe<Container>& other) : ctr(other.ctr)
{
    cout << "PmergeMe copy ctor is called" << endl;
}

template <typename Container>
PmergeMe<Container>& PmergeMe<Container>::operator=(const PmergeMe<Container>& other)
{
    if (this != &other)
    {
        cout << "PmergeMe operator= is called" << endl;
        ctr = other.ctr;
    }
    return (*this);
}

template <typename Container>
PmergeMe<Container>::~PmergeMe()
{
    cout << "PmergeMe dtor is called" << endl;
}

template <typename Container>
void    PmergeMe<Container>::fill_container(char** argv)
{
    for(size_t i = 1; argv[i]; ++i)
    {
        std::stringstream ss(argv[i]);

        long long elem;
        if (ss.str().find_first_not_of("0123456789") != std::string::npos || ss.str().size() > 10)
			throw std::runtime_error("Invaliiiid unput");
		ss >> elem;
		if (elem > INT_MAX)
			throw std::runtime_error("Invalieeed unput");
		ctr.push_back(elem);
    }
}

template <typename Container>
void	PmergeMe<Container>::print()
{
	for(size_t i = 0; i < ctr.size(); ++i)
		cout << ctr[i] << endl;
}

template <typename Container>
Container binary_search(Container big, Container small)
{
    while (!small.empty())
    {
        typename Container::iterator middle;
		typename Container::iterator left = big.begin();
        typename Container::iterator right = big.end() - 1;
        // int i = 1;//2^0
		while (left < right)
        {
            // if (i > small.size())
            //     i = 0;
			middle = left + std::distance(left, right) / 2;
            if (small[0] <= *middle)
                right = middle;
			else
                left = middle + 1;
        }
		big.insert(left, small[0]);
        small.erase(small.begin());
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

template <typename Container>
void PmergeMe<Container>::sort()
{
	ctr = rec(ctr);
}