#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : file_name("data.csv")
{
    cout << "BitcoinExchange default ctor is called" << endl;
	fill_map();
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
		_map.insert(std::make_pair<std::string, double>(key, value));
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
			// cout << "line = " << line << endl;
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
			key = trim(key);
			validate_key(key);

			value = trim(value);
			double val = validate_value(value);
			// cout << "mmm-->" << key << endl;
			search_key_in_map(key, val);
		}
		catch(std::exception& e)
		{
			cout << "Exception: " << e.what() << endl;
		}
    } else { 
       throw std::runtime_error("Invalid pipe");
    }
}

int BitcoinExchange::check_have_this_key_in_map(const std::string& cur_key)
{
	// cout << "vates->" << cur_key << endl;
	for (std::map<std::string, double>::iterator it = _map.begin(); it != _map.end(); ++it){
		if (it->first == cur_key)
		{
			// cout << "hres->" << it->first << endl;
			// cout << "hres->" << cur_key << endl;

			return (1);
		}
	}
	return (-1);
}

void	BitcoinExchange::search_key_in_map(std::string& key, double value)
{
	// cout << "bbeeeeee\n";
	std::map<std::string, double>::iterator it;
	// std::map<std::string, double>::iterator it_helper2 = _map.begin();
	if (key < "2009-01-02")
	{
		cout << "sranic hin data chka brats" << endl;
		return ;
	}
	// for (std::map<std::string, double>::iterator it = _map.begin(); it != _map.end(); ++it){
		// it = _map.lower_bound(key);
		// it = _map.lower_bound(key);
		cout << "eeee->" << value << endl;
		if (check_have_this_key_in_map(key) == 1)
		{
			// cout << "zibil\n";
			it = _map.lower_bound(key);
			// cout << key << " | " << value << " = " << it->second * value << endl;
			// continue ;
		}
		else
		{
			it = _map.lower_bound(key);
			if (it == _map.end())//Если key больше всех ключей
			{
				it--;
				// cout << "ooooooooooooooooooooo\n";
				// cout << key << " | " << value << " = " << it->second * value << endl;
			}
			else
			{
				it--;
				// it--;
				// cout << "vaxxxx\n";

				// it--;
			}
		}
			cout << key << " | " << value << " = " << it->second * value << endl;
	// }
}


//////////////////////validate_value////////////////////////
double    BitcoinExchange::validate_value(std::string& value)
{
	if (value.find_first_not_of("0123456789") != std::string::npos)
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
	// key = trim(key);
	 if (key.find_first_not_of("-0123456789") != std::string::npos || key.size() > 10)
		throw std::runtime_error("Invalid key");
	if (key[4] != '-' || key[7]!= '-' || len(key, '-') != 2)
		throw std::runtime_error("Invalid key");
	// std::string year;
	// std::string month;
	// std::string day;
	// try{
		int year = validate_year_and_month(key.substr(0, key.find('-')), 'y');
		int month = validate_year_and_month(key.substr(key.find('-') + 1, key.find_last_of('-')), 'm');
		validate_day(key.substr(key.find_last_of('-') + 1), year, month);
	// }
	// catch(std::exception& e)
	// {
	// 	cout << "Exception: " << e.what() << endl;
	// }
	
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
/////////////////////////////////////////////////////////////////////////

BitcoinExchange::~BitcoinExchange()
{
    cout << "BitcoinExchange dtor is called" << endl;
	file.close();
}