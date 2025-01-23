#include "iter.hpp"

int main()
{
	//array of integers
    const int int_arr[] = {5, 1, 3, 9, 10, 16};
	size_t iarr_len = sizeof(int_arr) / sizeof(int_arr[0]);
	iter(int_arr, iarr_len, func<int>);

	//array of doubles
	double double_arr[] = {5.1, 1.6, 3.6, 9.0, 10.7, 16.5};
	size_t darr_len = sizeof(double_arr) / sizeof(double_arr[0]);
	iter(double_arr, darr_len, func<double>);

	//array of chars
	char char_arr[] = {'a', 'b', 'c', 'd'};
	size_t carr_len = sizeof(char_arr) / sizeof(char_arr[0]);
	iter(char_arr, carr_len, func<char>);

	//array of strings
	const std::string string_arr[] = {"Arina", "Vrds", "Vahags", "brats" ,"heriqa lav"};
	size_t sarr_len = sizeof(string_arr) / sizeof(string_arr[0]);
	iter(string_arr, sarr_len, func<std::string>);

	//null-i depq
	const int* ptr = NULL;
	iter(ptr, iarr_len, func<int>);
}