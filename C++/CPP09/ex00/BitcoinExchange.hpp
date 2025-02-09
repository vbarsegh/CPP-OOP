#pragma once


#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>

using std::cout;
using std::endl;
class BitcoinExchange
{
private:
    std::string file_name;
    std::ifstream file;
    std::map<std::string, double> _map;
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();
    void    fill_map();
    void    simulation(char *argv1);
    void    split_line(std::string& line, std::string& date, std::string& value);
    std::string trim(const std::string& str);
    size_t  len(std::string str, char c);
    void    validate_key(std::string& key);
    int validate_year_and_month(std::string line_parts, char flag);
    void   	validate_day(std::string s_day, int year, int month);
    double    validate_value(std::string& value);
    void    search_key_in_map(std::string& key, double value);
	int check_have_this_key_in_map(const std::string& cur_key);

};