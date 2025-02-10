#include "RPN.hpp"

int main(int argc, char** argv)
{
    if (argc != 2)
	{
        std::cerr << "Invalid argument" << endl;
		return (-1);
	}
	std::string line = argv[1];
	if (line.find_first_not_of(" +-*/0123456789") != std::string::npos)
	{
		std::cerr << "Invalid input" << endl;
		return (-1);
	}
	RPN obj;
	try{
		cout << "Result: " << obj.member_func(argv[1]) << endl;
	}
	catch(std::exception& e)
	{
		cout << "Exception: " << e.what() << endl;
	}

}