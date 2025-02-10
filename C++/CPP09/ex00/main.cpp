#include "BitcoinExchange.hpp"




int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: Invalid argument." << std::endl;
        return 1;
    }
    try{
        BitcoinExchange obj;
        BitcoinExchange ob;
        ob = obj;
        obj.simulation(argv[1]);
    }
    catch(std::exception &e)
    {
        cout << "Exception: " << e.what() << endl;
    }
}