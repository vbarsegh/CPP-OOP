#include <iostream>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout <<"* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (1);
    }
    int i = 1;
    while (i < argc)
    {
        for (unsigned int j = 0; argv[i][j]; j++)
            std::cout << (char)toupper(argv[i][j]);
        i++;
    }
    std::cout << std::endl;
    return (0);
}
