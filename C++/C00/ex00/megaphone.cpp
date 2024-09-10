#include <iostream>
#include <string.h>

int main()
{
    std::string arr;
    getline(std::cin, arr);

    for (unsigned int i = 0; i < arr.length(); i++)
        std::cout << (char)toupper(arr[i]);
    std::cout << std::endl;

    return (0);
}
