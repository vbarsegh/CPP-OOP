#pragma once

#include <iostream>
#include <stack>
#include <sstream>
#include <cctype>
#include <limits>

using std::cout;
using std::endl;

class RPN
{
private:
	int _elem;
	std::stack<int> st;
public:
	RPN();
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);
	~RPN();
	int	member_func(char* argv1);
	void	operation(char);
	int		check_what_operation_must_be_make(char);
};