#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : file_name("data.csv")
{
    // cout << "BitcoinExchange default ctor is called" << endl;
	fill_map();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : file_name(other.file_name), _map(other._map)
{
    cout << "BitcoinExchange copy ctor is called" << endl;
	// std::ifstream нельзя копировать.
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		cout << "BitcoinExchange operator= is called" << endl;
		file_name = other.file_name;
		_map = other._map;
		// Если файл уже был открыт, закрываем его
        if (file.is_open())
            file.close();
		// Открываем файл заново (при необходимости)
        file.open(file_name.c_str()); 
        if (!file.is_open()) {
            throw std::runtime_error("Cannot open file in operator=");
        }
	}
	return (*this);
}


void	BitcoinExchange::fill_map()
{
	file.open(file_name.c_str());
	if (!file) {
        throw std::runtime_error("Cannot open data.csv!");//sra obj stxcely try-i mej anel
    }
	std::string line;
	std::string key;
    std::string val;
	double value;
	std::stringstream ss;
	getline(file, line);
	while (getline(file, line))
	{
		int ind = line.find(',');
		key = line.substr(0, ind);
		val = line.substr(ind + 1, line.size());
		ss << val;
		ss >> value;
		_map.insert(std::make_pair<std::string, double>(key, value));
		ss.clear();
	}
	// for (std::map<std::string, double>::iterator it = _map.begin(); it != _map.end(); ++it) {
    //     // it->first — это ключ, it->second — это значение
    //     std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
	// }
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
	getline(file, line);
	if (line != "date | value")
		throw std::runtime_error("Wrong first line in input.txt");
    while (getline(file, line))
    {
		try{
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
		key = line.substr(0, delimiter_pos);  // Левая часть — дата
        value = line.substr(delimiter_pos + 1);
		try{
			key = trim(key);
			validate_key(key);
			value = trim(value);
			double val = validate_value(value);
			search_key_in_map(key, val);
		}
		catch(std::exception& e)
		{
			cout << "Exception: " << e.what() << endl;
		}
    }
	else
       throw std::runtime_error("Invalid pipe");
}

int BitcoinExchange::check_have_this_key_in_map(const std::string& cur_key)
{
	for (std::map<std::string, double>::iterator it = _map.begin(); it != _map.end(); ++it){
		if (it->first == cur_key)
			return (1);
	}
	return (-1);
}

void	BitcoinExchange::search_key_in_map(std::string& key, double value)
{
	std::map<std::string, double>::iterator it;
	if (key < "2009-01-02")
		throw std::runtime_error("2009-01-02 ic hin amsativ!!");
	if (check_have_this_key_in_map(key) == 1)
		it = _map.lower_bound(key);
	else
	{
		it = _map.lower_bound(key);
		it--;
	}
		cout << key << " | " << value << " = " << it->second * value << endl;
}


//////////////////////validate_value////////////////////////
double    BitcoinExchange::validate_value(std::string& value)
{
	if (value.find_first_not_of(".0123456789") != std::string::npos)
		throw std::runtime_error("Invalid value");
	double	val;
	std::stringstream ss;
	ss << value;
	ss >> val;
	if (ss.fail())
		throw std::runtime_error("std::stringstream failed");
	if (val < 0 || val > 1000)
		throw std::runtime_error("Invalid value");
	ss.clear();
	return (val);
}

/////////////////////////////////////////////////////////////

//////////////////////validate_key////////////////////////
void    BitcoinExchange::validate_key(std::string& key)
{
	 if (key.find_first_not_of("-0123456789") != std::string::npos || key.size() > 10)
		throw std::runtime_error("Invalid key");
	if (key[4] != '-' || key[7]!= '-' || len(key, '-') != 2)
		throw std::runtime_error("Invalid key");
	int year = validate_year_and_month(key.substr(0, key.find('-')), 'y');
	int month = validate_year_and_month(key.substr(key.find('-') + 1, key.find_last_of('-')), 'm');
	validate_day(key.substr(key.find_last_of('-') + 1), year, month);
}

int	BitcoinExchange::validate_year_and_month(std::string line_parts, char flag)
{
	int	elem;
	std::stringstream ss;
	ss << line_parts;
	ss >> elem;
	if (ss.fail())
		throw std::runtime_error("std::stringstream failed");
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
	ss.clear();//petqa vor?
	return (-1);
}

void	BitcoinExchange::validate_day(std::string s_day, int year, int month)
{
	int	day;
	std::stringstream ss;
	ss << s_day;
	ss >> day;
	if (ss.fail())
		throw std::runtime_error("std::stringstream failed");
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
		else if (day < 0 || day > 28)
			throw std::runtime_error("Invalid day");
	}
	ss.clear();//?
}
/////////////////////////////////////////////////////////////////////////


///////////////////////utils_functions//////////////////////////////////
std::string BitcoinExchange::trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \n\v\r\f\t");
    if (first == std::string::npos) return ""; // Если строка состоит только из пробелов

    size_t last = str.find_last_not_of(" \n\v\r\f\t");
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
/////////////////////////////////////////////////////////////////////////

BitcoinExchange::~BitcoinExchange()
{
    // cout << "BitcoinExchange dtor is called" << endl;
	file.close();
}