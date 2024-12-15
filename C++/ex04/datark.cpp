#include <iostream>

// #define i 5
int i = 5;

int sum(int i, int b)
{
    std:: cout << ::i << " " << b << std::endl;
    return (i + b);
}


int main()
{
    sum (7, 2);

    return 0;
}