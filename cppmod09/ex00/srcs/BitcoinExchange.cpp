//
// Created by rdas-nev on 4/11/23.
//

#include "../inc/BitcoinExchange.hpp"

// Orthodox Canonical Form =====================================================
BitcoinExchange::BitcoinExchange()
{
	this->fill_database();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	this->data = other.data;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}
// =============================================================================

// DataBase ====================================================================
void BitcoinExchange::fill_database() // Fill the database ---------------------
{
	std::ifstream file ("data.csv");
	if (!file.is_open())
		throw CouldntOpenFile();

	std::string line;
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string key, value;

		std::getline(ss, key, ',');
		if (std::getline(ss, value, ','))
			data[key]  = value;
		else
			data[key] = "No Value";
	}
	file.close();
}

void BitcoinExchange::show_database() // Show the database ---------------------
{
	for(dictionary::iterator it = data.begin(); it != data.end(); ++it)
		std::cout << it->first << " : " << it->second << std::endl;
}

std::string BitcoinExchange::get_from_key(std::string key)
{
	if (data.find(key) != data.end())
		return "ola";
	else
		return "adeus";
}
// =============================================================================

// Test ========================================================================
void isValidDate(std::string dateStr)
{
	if (dateStr.length() != 10)
		throw BitcoinExchange::InvalidDate();
	if (dateStr[4] != '-' || dateStr[7] != '-')
		throw BitcoinExchange::InvalidDate();
	std::string yearStr = dateStr.substr(0, 4);
	std::string monthStr = dateStr.substr(5, 2);
	std::string dayStr = dateStr.substr(8, 2);
	int year, month, day;
	std::istringstream(yearStr) >> year;
	std::istringstream(monthStr) >> month;
	std::istringstream(dayStr) >> day;
	if (year < 0 || year > 9999 || month < 1 || month > 12 || day < 1 || day > 31)
		throw BitcoinExchange::InvalidDate();
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		throw BitcoinExchange::InvalidDate();
	if (month == 2) {
		if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
			if (day > 29)
				throw BitcoinExchange::InvalidDate();
		} else {
			if (day > 28)
				throw BitcoinExchange::InvalidDate();
		}
	}
}

void isValidQuantity(float quantity)
{
	if (quantity < 0)
		throw BitcoinExchange::NegativeNumber();
	else if (quantity > 1000 || quantity > (float)std::numeric_limits<int>::max())
		throw BitcoinExchange::TooLargeNumber();
}

int date_diff_in_days(const std::string& date1, const std::string& date2)
{
	int year1, month1, day1, year2, month2, day2;
	std::istringstream iss1(date1);
	std::istringstream iss2(date2);
	char delimiter;
	iss1 >> year1 >> delimiter >> month1 >> delimiter >> day1;
	iss2 >> year2 >> delimiter >> month2 >> delimiter >> day2;
	int days_in_month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int leap_days_in_month[13] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int diff_days = 0;
	for (int y = year1; y < year2; y++) {
		if (y % 4 == 0) {
			diff_days += 366;
		} else {
			diff_days += 365;
		}
	}
	int* days_in_curr_month = (year2 % 4 == 0) ? leap_days_in_month : days_in_month;
	for (int m = 1; m < month2; m++) {
		diff_days += days_in_curr_month[m];
	}
	diff_days += day2;
	days_in_curr_month = (year1 % 4 == 0) ? leap_days_in_month : days_in_month;
	for (int m = 1; m < month1; m++) {
		diff_days -= days_in_curr_month[m];
	}
	diff_days -= day1;
	return diff_days;
}

std::string BitcoinExchange::get_closest_lower_date(const std::string& date)
{
	std::string closest_key = "";
	int min_diff = std::numeric_limits<int>::max();
	for (std::map<std::string, std::string>::iterator it = data.begin(); it != data.end(); ++it)
	{
		const std::string& key = it->first;
		if (key <= date && date_diff_in_days(key, date) < min_diff)
		{
			closest_key = key;
			min_diff = date_diff_in_days(key, date);
		}
	}
	return closest_key;
}

void BitcoinExchange::line_by_line(std::string date, float quantity)
{
	try
	{
		isValidDate(date);
		isValidQuantity(quantity);
		std::string key = get_closest_lower_date(date);
		float value = static_cast<float>(atof(data[key].c_str()));
		std::cout << date << " => " << quantity << " = " << value * quantity << std::endl;
	}
	catch (BitcoinExchange::InvalidDate &e)
	{
		std::cout << e.what() << date << std::endl;
	}
	catch (BitcoinExchange::NegativeNumber &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (BitcoinExchange::TooLargeNumber &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void BitcoinExchange::get_value(char *input_file)
{
	std::string date, quantity;

	std::ifstream file (input_file);
	if (!file.is_open())
		throw CouldntOpenFile();
	// -------------------------------------------------------------------------
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string placeholder;

		std::getline(ss, date, '|');
		if (std::getline(ss, placeholder, '|'))
			quantity  = placeholder;
		else
			quantity = "No Value";
		// ---------------------------------------------------------------------
		try
		{
			float quant;
			if (quantity == "No Value")
				throw BadInput();
			else
				quant = static_cast<float>(atof(quantity.c_str()));
			date = date.substr(0, date.length() - 1);
			line_by_line(date, quant);
		}
		catch (CouldntOpenFile &e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << date << std::endl;
		}
	}
	file.close();
}
// =============================================================================

// Class Exceptions ============================================================
const char *BitcoinExchange::CouldntOpenFile::what() const throw()
{
	return "Error opening file.";
}

const char *BitcoinExchange::InvalidDate::what() const throw()
{
	return "Error: bad input: => ";
}

const char *BitcoinExchange::NegativeNumber::what() const throw()
{
	return "Error: not a positive number.";
}

const char *BitcoinExchange::TooLargeNumber::what() const throw()
{
	return "Error: too large a number.";
}

const char *BitcoinExchange::BadInput::what() const throw()
{
	return "Error: bad input => ";
}
// =============================================================================
