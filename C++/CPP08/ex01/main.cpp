#include "Span.hpp"

// int main()
// {
//     Span obj(10);
//     obj.addNumber(-2);
//     obj.addNumber(-6);
//     obj.addNumber(-214);
//     // for (int i = 0; i < 3; i++)
//     // {
//     //     cout << obj.get_vec_num(i) << endl;
//     // }
//     std::vector<int> arr(5, 10);
//     try
//     {
//         obj.TaddNumber(arr.begin(), arr.end());
//         for (int i = 0; i < 8; i++)
//         {
//             cout << obj.get_vec_num(i) << endl;
//         }
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     cout << "shortestspan->" << obj.shortestSpan() << endl;
//     cout << "longestspan->" << obj.longestSpan() << endl;

// }

int main()
{
    try {
		std::cout << "\033[0;32m[" << "Testing addNumber" << "]\033[0m" << std::endl;
		Span sp = Span(10);
		sp.addNumber(77);
		sp.addNumber(10);
		sp.addNumber(88);
		std::cout << "LongestSpan: " << sp.longestSpan() << std::endl;
		std::cout << "ShortestSpan: " << sp.shortestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "\033[0;31m[" << e.what() << "]\033[0m" << std::endl;
	}
    //////////////////////////////////////////////////////
    try {
		std::cout << "\033[0;32m[" << "Testing insert" << "]\033[0m" << std::endl;
		Span sp = Span(10);
		int arr[] = {1, 2, 3, 4, 5};
        sp.TaddNumber(arr, arr + 5);
	}
	catch (const std::exception& e) {
		std::cout << "\033[0;31m[" << e.what() << "]\033[0m" << std::endl;
	}


    //////////////////////////////////////////////////////
    try {
		Span sp(10);
		std::cout << "\033[0;32m[" << "Testing longestSpan on empty span" << "]\033[0m" << std::endl;
		long long	longestspan = sp.longestSpan();
		std::cout << "LongestSpan: " << longestspan << std::endl;

	}
	catch (const std::exception& e){
		std::cout << "\033[0;31m[" << e.what() << "]\033[0m" << std::endl;
	}
	// -------------------------------------------------------------------------------------
	try {
		Span sp(10);
		std::cout << "\033[0;32m[" << "Testing shortestSpan" << "]\033[0m" << std::endl;
		long long	shortestspan = sp.shortestSpan();
		std::cout << "ShortestSpan: " << shortestspan << std::endl;
	}
	catch (const std::exception& e){
		std::cout << "\033[0;31m[" << e.what() << "]\033[0m" << std::endl;
	}
    ////////////////////////////////////////////////////////////
    try {
		Span sp(2);
		std::cout << "\033[0;32m[" << "Add more elements than N" << "]\033[0m" << std::endl;
		std::vector<int> vect(5,10);
		sp.TaddNumber(vect.begin(), vect.end());
	}
	catch (const std::exception& e){
		std::cout << "\033[0;31m[" << e.what() << "]\033[0m" << std::endl;
	}
}