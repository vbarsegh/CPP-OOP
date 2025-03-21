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
	const std::string string_arr[] = {"hres", "Vrds", "Vahags", "brats" ,"heriqa lav"};
	size_t sarr_len = sizeof(string_arr) / sizeof(string_arr[0]);
	iter(string_arr, sarr_len, func<std::string>);

	//null-i depq
	const int* ptr = NULL;
	iter(ptr, iarr_len, func<int>);
}


// class Awesome
// {
//   public:
//     Awesome( void ) : _n( 42 ) { return; }
//     int get( void ) const { return this->_n; }
//   private:
//     int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
// {
//   o << rhs.get();
//   return o;
// }

// template< typename T >
// void print( T& x )
// {
//   std::cout << x << std::endl;
//   return;
// }

// int main() {
//   int tab[] = { 0, 1, 2, 3, 4 };
//   Awesome tab2[5];

//   iter( tab, 5, print<const int> );
//   iter( tab2, 5, print<Awesome> );

//   return 0;
// }


