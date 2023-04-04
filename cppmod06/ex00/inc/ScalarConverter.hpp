//
// Created by rdas-nev on 4/3/23.
//

#ifndef INC_42_CPP_MODULES_SCALARCONVERTER_H
#define INC_42_CPP_MODULES_SCALARCONVERTER_H

#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cstdio>
#include <cctype>
#include <stdexcept>
#include <cmath>
#include <limits>

enum
{
	CHAR = 1,
	INT = 2,
	FLOAT = 3,
	DOUBLE = 4
};

class ScalarConverter
{
	private:
	// Orthodox Canonical Form
		ScalarConverter();
		ScalarConverter(ScalarConverter const &other);
		ScalarConverter &operator=(ScalarConverter const &other);
		~ScalarConverter();
	// Attributes to hold conversion results
		static char		_char;
		static int		_int;
		static float	_float;
		static double	_double;
		static int 		_checkchar;
		static int 		_checkint;
		static int 		_checkfloat;
	public:
	// Convert methods
		static void convert_from_char(std::string const &str);
		static void convert_from_int(std::string const &str);
		static void convert_from_float(std::string const &str);
		static void convert_from_double(std::string const &str);
		static void convert(std::string const &cpp_literal);
	// Show values
		static void show_values();
	// Get Literal Type
		static int getLiteralType(const std::string &str);
	// Class Exceptions
		class InvalidInput : std::exception
		{
			public:
				const char *what() const throw();
		};
};

#endif //INC_42_CPP_MODULES_SCALARCONVERTER_H
