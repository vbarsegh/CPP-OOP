#include "easyfind.hpp"
using std::cout;
using std::endl;
int main()
{
    int init_values[] =  {1, 2, 3, 4, 5};
    std::vector<int> vec(init_values, init_values + (sizeof(init_values) / sizeof(init_values[0])));
    try
    {
       cout << &vec[4] << endl;
       std::vector<int>::iterator it = easyfind(vec, 6);
       cout << &(*it) << endl;
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}