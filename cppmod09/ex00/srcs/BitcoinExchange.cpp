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
// =============================================================================

// Validate ====================================================================
void BitcoinExchange::isValidDate(std::string dateStr)
{
	if (dateStr.length() != 10)
		throw InvalidDate();
	if (dateStr[4] != '-' || dateStr[7] != '-')
		throw InvalidDate();
	std::string yearStr = dateStr.substr(0, 4),
	 			monthStr = dateStr.substr(5, 2),
	 			dayStr = dateStr.substr(8, 2);
	int year, month, day;
	std::istringstream(yearStr) >> year;
	std::istringstream(monthStr) >> month;
	std::istringstream(dayStr) >> day;
	if (year < 0 || year > 9999 || month < 1 || month > 12 || day < 1 || day > 31)
		throw InvalidDate();
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		throw InvalidDate();
	if (month == 2)
	{
		if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
		{
			if (day > 29)
				throw InvalidDate();
		}
		else
		{
			if (day > 28)
				throw InvalidDate();
		}
	}
}

void BitcoinExchange::isValidQuantity(float quantity)
{
	if (quantity < 0)
		throw NegativeNumber();
	else if (quantity > 1000 || quantity > (float)std::numeric_limits<int>::max())
		throw TooLargeNumber();
}
// =============================================================================

// Closest date ================================================================
int BitcoinExchange::date_diff_in_days(const std::string &date1, const std::string &date2)
{
	struct std::tm time1 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	struct std::tm time2 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	std::istringstream ss1(date1);
	std::istringstream ss2(date2);
	std::memset(&time1, 0, sizeof(struct std::tm));
	std::memset(&time2, 0, sizeof(struct std::tm));
	ss1 >> time1.tm_year;
	ss1.ignore(1);
	ss1 >> time1.tm_mon;
	ss1.ignore(1);
	ss1 >> time1.tm_mday;
	ss2 >> time2.tm_year;
	ss2.ignore(1);
	ss2 >> time2.tm_mon;
	ss2.ignore(1);
	ss2 >> time2.tm_mday;
	time1.tm_year -= 1900;
	time1.tm_mon--;
	time2.tm_year -= 1900;
	time2.tm_mon--;
	std::time_t t1 = std::mktime(&time1);
	std::time_t t2 = std::mktime(&time2);
	double diff_seconds = std::difftime(t1, t2);
	int diff_days = (int)std::abs(diff_seconds / (60 * 60 * 24));
	return diff_days;
}

std::string BitcoinExchange::get_closest_lower_date(const std::string& date)
{
	std::string closest_key = "";
	int min_diff = std::numeric_limits<int>::max();
	std::map<std::string, std::string>::iterator it;
	for (it = data.begin() ; it != data.end(); ++it)
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
// =============================================================================

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
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void BitcoinExchange::get_value(char *input_file)
{
	try
	{
		std::ifstream file (input_file);
		if (!file.is_open())
			throw CouldntOpenFile();
		// -------------------------------------------------------------------------
		std::string line, placeholder, date, quantity, fl;
		std::ifstream check_fl(input_file);
		std::getline(check_fl, fl);
		if (fl == "date | value")
			std::getline(file, line);
		while (std::getline(file, line))
		{
			std::stringstream ss(line);
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
			catch (std::exception &e)
			{
				std::cout << e.what() << date << std::endl;
			}
		}
		file.close();
	}
	catch (CouldntOpenFile &e)
	{
		std::cout << e.what() << std::endl;
	}
}
// =============================================================================

// Class Exceptions ============================================================
const char *BitcoinExchange::CouldntOpenFile::what() const throw()
{
	return "Error: could not open file.";
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
