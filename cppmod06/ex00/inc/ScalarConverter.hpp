//
// Created by rdas-nev on 4/3/23.
//

#ifndef INC_42_CPP_MODULES_SCALARCONVERTER_H
#define INC_42_CPP_MODULES_SCALARCONVERTER_H

#include <iostream>
#include <sstream>

class ScalarConverter
{
	private:
		static char		attribute_char;
		static int		attribute_int;
		static float	attribute_float;
		static double	attribute_double;
		ScalarConverter();
		ScalarConverter(ScalarConverter const &other);
//		ScalarConverter &operator=(ScalarConverter const &other);
		~ScalarConverter();
	public:
	// Convert method
		static void convert(std::string cpp_literal);
	// Print method
		static void show_values();
};

#endif //INC_42_CPP_MODULES_SCALARCONVERTER_H
