#include "Span.hpp"

int main()
{
    Span obj(10);
    obj.addNumber(-2);
    obj.addNumber(6);
    obj.addNumber(9);
    for (int i = 0; i < 3; i++)
    {
        cout << obj.get_vec_num(i) << endl;
    }
    // std::vector<int> arr(5, 10);
    // try
    // {
    //     obj.TaddNumber<std::vector<int> >(arr.begin(), arr.end());
    //     for (int i = 0; i < 11; i++)
    //     {
    //         cout << obj.get_vec_num(i) << endl;
    //     }
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    cout << "shortestspan->" << obj.shortestSpan() << endl;
    cout << "longestspan->" << obj.longestSpan() << endl;

}