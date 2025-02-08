#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : file_name("data.csv")
{
    cout << "BitcoinExchange default ctor is called" << endl;
	fill_map();
}

void	BitcoinExchange::fill_map()
{
	file.open(file_name);
	if (!file) {
        throw std::runtime_error("Cannot open data.csv!");//sra obj stxcely try-i mej anel
    }
	std::string line;
	std::string key;
    std::string val;
	int count = 0;
	double value;
	std::stringstream ss;
	while (getline(file, line))
	{
		if (count == 0)
		{
			count++;
			continue ;
		}
		int ind = line.find(',');
		key = line.substr(0, ind);
		val = line.substr(ind + 1, line.size());
		// cout << "vaaaaaal = " << val;
		// cout << "size = " << line.size()<< endl;
		ss << val;
		ss >> value;
		// cout << "key = " << key << "  " << "value = " << value << endl;
		_map.insert(std::make_pair(key, value));
		ss.clear();
	}
	for (std::map<std::string, double>::iterator it = _map.begin(); it != _map.end(); ++it) {
        // it->first — это ключ, it->second — это значение
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
	}
}

void	BitcoinExchange::simulation(char *argv1)
{
	std::ifstream file(argv1);
    if (!file) {
        throw std::runtime_error("Cannot open argv1!");
    }
	std::string line;
    std::string key;
    std::string value;
	int count = 0;
    while (getline(file, line))
    {
		try{
			if (count == 0)
			{
				++count;
				continue ;
			}
			split_line(line, key, value);
		}
		catch(std::exception& e)
		{
			cout << e.what() << endl;
		}
    }
    file.close();
}

void BitcoinExchange::split_line(std::string& line, std::string& key, std::string& value) {
    size_t delimiter_pos = line.find('|'); // Ищем разделитель " | "
    
    if (delimiter_pos != std::string::npos && len(line, '|') == 1) {// Если найдено
		line = trim(line);//demi u verji white spascery hanaca
        key = line.substr(0, delimiter_pos);  // Левая часть — дата
        value = line.substr(delimiter_pos + 1);
		try{
			validate_key(key);
			// validate_value(value);
		}
		catch(std::exception& e)
		{
			cout << "Exception: " << e.what() << endl;
		}
    } else { 
       throw std::runtime_error("Invalid pipe");
    }
}


void    BitcoinExchange::validate_key(std::string& key)
{
	key = trim(key);
	 if (key.find_first_not_of("-0123456789") != std::string::npos || key.size() > 10)
		throw std::runtime_error("Invalid key");
	if (key[4] != '-' || key[7]!= '-' || len(key, '-') != 2)
		throw std::runtime_error("Invalid key");
	std::string year;
	std::string month;
	std::string day;
	// std::stringstream ss;
	try{
		int year = validate_year_and_month(key.substr(0, key.find('-')), 'y');
		int month = validate_year_and_month(key.substr(key.find('-') + 1, key.find_last_of('-')), 'm');
		validate_day(key.substr(key.find_last_of('-') + 1), year, month);
	}
	catch(std::exception& e)
	{
		cout << "Exception: " << e.what() << endl;
	}
	
}

void	BitcoinExchange::validate_day(std::string s_day, int year, int month)
{
	int	day;
	std::stringstream ss;
	ss << s_day;
	ss >> day;
	
	if (month == 1 || month == 3 || month == 5
		|| month == 7 || month == 8 || month == 10 || month == 12)
	{
		if (day < 0 || day > 31)
			throw std::runtime_error("Invalid day");
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day < 0 || day > 30)
			throw std::runtime_error("Invalid day");
	}
	else if (month == 2)
	{
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			if (day < 0 || day > 29)
			throw std::runtime_error("Invalid day");
		}
		else
			if (day < 0 || day > 28)
				throw std::runtime_error("Invalid day");
	}
}

int	BitcoinExchange::validate_year_and_month(std::string line_parts, char flag)
{
	int	elem;
	std::stringstream ss;
	ss << line_parts;
	ss >> elem;
	if (flag == 'y')
	{
		if (elem < 0 || elem > 9999)
			throw std::runtime_error("Invalid year");
		return (elem);
	}
	if (flag == 'm')
	{
		if (elem < 1 || elem > 12)
			throw std::runtime_error("Invalid month");
		return (elem);
	}
	return (-1);
}

std::string BitcoinExchange::trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \n\v\t");
    if (first == std::string::npos) return ""; // Если строка состоит только из пробелов

    size_t last = str.find_last_not_of(" \t");
    return str.substr(first, last - first + 1);
}

size_t BitcoinExchange::len(std::string str, char c)
{
    size_t count = 0;
  for (size_t i = 0; i < str.length(); i++) {
        if (str[i] == c)
            count++;
    }
    return (count);
}

BitcoinExchange::~BitcoinExchange()
{
    cout << "BitcoinExchange dtor is called" << endl;
	file.close();
}