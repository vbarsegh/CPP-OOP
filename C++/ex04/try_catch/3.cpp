#include <iostream>

int paragic_triangle(int a, int b, int c)
{
    try
    {   
        if (a < 0 || b < 0 || c < 0)
            throw -1;
    }
    // catch(int x)
    // {
    //     std::cout << x << std::endl;
    //     return x;
    // }orinak1
    
    // catch(double x)
    // {
    //     std::cout << x << std::endl;
    //     return x;
    // }orinak2

    catch(int x)
    {
        std::cout << x << std::endl;
        throw;
    }//orinak3
    if (a > b + c || b > a + c || c > a + c)
        throw "Error: a, b, c are not triangle lenghts";
    return (a + b + c);
}

int main()
{
    try
    {
        int p = paragic_triangle(-5,1,2);
        std::cout << "cuyc talu hamar vor ete paragic_triangle-i mej throw-n ashxati el es cout-is chi hasnelu" << std::endl;
    }
    catch(const char* e)
    {
        std::cout << e << std::endl;
    }
    catch(int)
    {
        std::cout << "Lenght must be positive digitals" << std::endl;
    }


    return (0);
}
