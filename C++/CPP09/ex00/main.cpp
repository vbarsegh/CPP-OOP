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
        // while ()
        obj.simulation(argv[1]);
    }
    catch(std::exception &e)
    {
        cout << "Exception: " << e.what() << endl;
    }
    // file.close();
}