#include "easyfind.hpp"
using std::cout;
using std::endl;

void    test0()
{
     /////with const
    const int init_values[] =  {1, 2, 3, 4, 5};
    const std::vector<int> vec(init_values, init_values + (sizeof(init_values) / sizeof(init_values[0])));
    try
    {
    cout << &vec[4] << endl;
    std::vector<int>::const_iterator it = easyfind(vec, 4);
    cout << &(*it) << endl;
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << e.what() << '\n';
    }
}
void    test1()
{
 ///////bez const
    int init_values[] =  {1, 2, 3, 4, 5};
    std::vector<int> vec(init_values, init_values + (sizeof(init_values) / sizeof(init_values[0])));
    try
    {
    cout << &vec[4] << endl;
    std::vector<int>::iterator it = easyfind(vec, 4);
    cout << &(*it) << endl;
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void    test2()
{
    //stexcum enq datark vector
    std::vector<int> vec;
    try{
        std::vector<int>::iterator it  = easyfind(vec, 5);
        cout << "it->" << *it << endl;//kyanqum ste chi hasnelu, ete heto vectory ruchnoy chlcnenq
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void    test3()
{
    std::vector<int> vec(5, 10);
     try{
        std::vector<int>::iterator it  = easyfind(vec, 10);
        it += 4;
        cout << "it->" << *it << endl;//kyanqum ste chi hasnelu, ete heto vectory ruchnoy chlcnenq
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << e.what() << '\n';
    }

}

void    push_backk()
{
    std::vector<int> v;

	v.push_back(8);
	v.push_back(54);
	v.push_back(12);
	v.push_back(-7);
	v.push_back(95);
	v.push_back(1222);

	try {
		std::vector<int>::const_iterator it = easyfind(v, 54);
		std::cout << it[0] << std::endl;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	try {
		std::vector<int>::const_iterator it = easyfind(v, 6);
		std::cout << it[0] << std::endl;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	for (size_t i = 0; i < v.size(); i++)
		cout << "->" << v[i] << endl;
}
int main()
{
    cout << "test0\n";
    test0();
    cout << "test1\n";
    test1();
    cout << "test2\n";
    test2();
    cout << "test3\n";
    test3();
    cout << "testverjin\n";
    push_backk();
}