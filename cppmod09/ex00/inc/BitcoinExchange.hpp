//
// Created by rdas-nev on 4/11/23.
//

#ifndef INC_42_CPP_MODULES_BITCOINEXCHANGE_HPP
#define INC_42_CPP_MODULES_BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <limits>
#include <iomanip>

typedef std::map<std::string, std::string> dictionary;

class BitcoinExchange
{
		dictionary data;
	public:
	// Orthodox Canonical Form
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &other);
		BitcoinExchange &operator=(BitcoinExchange const &other);
		~BitcoinExchange();
	// DataBase
		void fill_database();
		void show_database();
	// Test
		std::string get_closest_lower_date(const std::string& date);
		std::string get_from_key(std::string key);
		void line_by_line(std::string date, float q);
		void get_value(char *input_file);
	// Class exceptions
		class CouldntOpenFile : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class InvalidDate : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class NegativeNumber : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class TooLargeNumber : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class BadInput : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

template<typename K, typename V>
std::map<K, V> reverseMap(const std::map<K, V>& originalMap)
{
	std::map<K, V> reversedMap;
	typename std::map<K, V>::const_reverse_iterator rit;
	for (rit = originalMap.rbegin(); rit != originalMap.rend(); ++rit)
	{
		reversedMap.insert(std::make_pair(rit->first, rit->second));
	}
	return reversedMap;
}

#endif //INC_42_CPP_MODULES_BITCOINEXCHANGE_HPP
