#include <iostream>

int paragic_triangle(int a, int b, int c)
{
    if (a < 0 || b < 0 || c < 0 || a > b + c || b > a + c || c > a + c)
        throw "Error: a, b, c are not triangle lenghts";
    return (a + b + c);
}
// Orinak1
// int main()
// {
//     int p = paragic_triangle(5,1,2);
//     //ete try catch grac chunenam u paragic_triangle-um throw-n ashxati kampilatory ira komic kirakanacni taki 2 funkcianery
//     //1)std::terminate()  terminating with uncaught exception of type char const*->ay senc message a tpum et std::terminate funkciayum   
//     //2)std::abort()
//     return (0);
// }

// Orinak2
int main()
{
    try
    {
        int p = paragic_triangle(5,1,2);
        std::cout << "cuyc talu hamar vor ete paragic_triangle-i mej throw-n ashxati el es cout-is chi hasnelu" << std::endl;
    }
    catch(const char* e)
    {
        std::cout << e << std::endl;
    }
    
    return (0);
}