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
size_t PmergeMe<Container>::len(std::string str, char c)
{
    size_t count = 0;
  for (size_t i = 0; i < str.length(); i++) {
        if (str[i] == c)
            count++;
    }
    return (count);
}

template <typename Container>
char* PmergeMe<Container>::trim(char* str) {
    while (*str == ' ') str++; // Убираем пробелы в начале

    char* end = str + std::strlen(str) - 1;
    while (end > str && *end == ' ') end--; // Убираем пробелы в конце

    *(end + 1) = '\0'; // Завершаем строку
    return str;
}

template <typename Container>
void    PmergeMe<Container>::fill_container(char** argv)
{
    for(size_t i = 1; argv[i]; ++i)
    {
        std::stringstream ss(argv[i]);
        std::string str = ss.str();
            cout << "str= " << str<<endl;
        long long elem;
        if (str.find_first_not_of(" +0123456789") != std::string::npos || str.size() > 10)
			throw std::runtime_error("Invaliiiid unput");
        size_t z = std::count(str.begin(), str.end(), '+');
        cout << "z = " <<z << endl;
        str = trim(argv[i]);
        cout << "trim str->" << str << endl;
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

template <typename Container>
void	PmergeMe<Container>::print()
{
	for(size_t i = 0; i < ctr.size(); ++i)
		cout << ctr[i] << endl;
}

template <typename Container>
Container binary_search(Container big, Container small)
{
    size_t i = 1;//2^0
    while (!small.empty())
    {
        cout << "i = "<<i<<endl;
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
    cout << endl;
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