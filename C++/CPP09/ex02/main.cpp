#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
    if (argc == 1)
    {
        std::cerr << "Invalid count" << endl;
        return (1);
    }
    PmergeMe<std::deque<int> > obj;
    (void)argv;
    obj.fill_container(argv);
    obj.sort();
    obj.print();
}