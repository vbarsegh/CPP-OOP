#include "MutantStack.hpp"

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(){
	cout << "MutantStack defaullt ctor is called" << endl;
}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack<T, Container>& other) : std::stack<T>(other){
	cout << "MutantStack copy ctor is called" << endl;
}

template <typename T, typename Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack<T, Container>& other){
	if (this != &other)
	{
		cout << "MutantStack operator aasignment is called" << endl;
		std::stack<T>::operator=(other);
	}
	return (*this);
}

template <typename T, typename Container>
typename std::stack<T, Container>::container_type::iterator MutantStack<T, Container>::begin(){
	return (this->c.begin());
}

template <typename T, typename Container>
typename std::stack<T, Container>::container_type::iterator MutantStack<T, Container>::end(){
	return (this->c.end());
}

template <typename T, typename Container>
typename std::stack<T, Container>::container_type::reverse_iterator MutantStack<T, Container>::rbegin(){
	return (this->c.rbegin());
}

template <typename T, typename Container>
typename std::stack<T, Container>::container_type::reverse_iterator MutantStack<T, Container>::rend(){
	return (this->c.rend());
}



template <typename T, typename Container>
typename std::stack<T, Container>::container_type::const_iterator MutantStack<T, Container>::cbegin() const{
	return (this->c.cbegin());
}

template <typename T, typename Container>
typename std::stack<T, Container>::container_type::const_iterator MutantStack<T, Container>::cend() const{
	return (this->c.cend());
}

template <typename T, typename Container>
typename std::stack<T, Container>::container_type::const_reverse_iterator MutantStack<T, Container>::crbegin() const{
	return (this->c.crbegin());
}

template <typename T, typename Container>
typename std::stack<T, Container>::container_type::const_reverse_iterator MutantStack<T, Container>::crend() const{
	return (this->c.crend());
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack(){
	cout << "MutantStack dtor is called" << endl;
}