#include <iostream>

int paragic_triangle(int a, int b, int c)
{
    if (a < 0 || b < 0 || c < 0)
        throw -1;
    if (a > b + c || b > a + c || c > a + c)
        throw "Error: a, b, c are not triangle lenghts";
    return (a + b + c);
}

// int main()
// {
//     try
//     {
//         int p = paragic_triangle(-5,1,2);
//         std::cout << "cuyc talu hamar vor ete paragic_triangle-i mej throw-n ashxati el es cout-is chi hasnelu" << std::endl;
//     }
//     catch(const char* e)
//     {
//         std::cout << e << std::endl;
//     }
//     //en aborti momentna ylnelu,vortev im grac catch-i mej chi mtnelu,vortev thrown -1a veradardznelu isk es int-i hamar catch chunem grac menak const char*-i hamar unem
//     return (0);
// }

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
    }//mekel senc mi ban,kam mer grac catcheric mekna ashxatelu kam vochmek,chi kara miqani catch ashxati,ete mihaty ashxatav,myusnery el chi nayum(ignoruma)
    return (0);
}