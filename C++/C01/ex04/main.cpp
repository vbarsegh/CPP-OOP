#include <iostream>
#include <string>
#include <fstream>

int	strlenn(char *str)
{
	int len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

std::string foo(std::string line, char *s1, char *s2)
{
	int	ind;
	int	len_s1;

	while (1)
	{
		ind = line.find(s1);
		if (ind == -1)
			break ;
		len_s1 = strlenn(s1);
		line.erase(ind, len_s1);//jnjuma
		line.insert(ind, s2);//avelacnuma
	}
	return (line);
}

int main(int argc, char **argv)
{
	std::string name_file = argv[1];

    if (argc != 4)
		return (std::cout << "Wrong input!" << std::endl && 1);
	std::ifstream cur_file;
	cur_file.open(argv[1]);
	if (!cur_file.is_open())
		return (std::cout << "Cannot open file" << std::endl && 1);
	std::string	line_in_file;
	std::string	poxvac_line;
	std::ofstream final_file(name_file + ".replace");
	while (getline(cur_file, line_in_file))
	{
		if (argv[2][0] == '\0')
			final_file << line_in_file << std::endl;
		else
		{	
			poxvac_line = foo(line_in_file, argv[2], argv[3]);
			final_file << poxvac_line << std::endl;
		}
	}
	cur_file.close();
	final_file.close();
	return (0);
}