//
// Created by rdas-nev on 4/3/23.
//

#include "../inc/ScalarConverter.hpp"

// Orthodox Canonical Form =====================================================
ScalarConverter::ScalarConverter()
{
//	attribute_char = '\0';
//	attribute_int = 0;
//	attribute_float = 0.0f;
//	attribute_double = 0.0;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	*this = other;
}

//ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
//{
////	this->attribute_char = other.attribute_char;
////	this->attribute_int = other.attribute_int;
////	this->attribute_float = other.attribute_float;
////	this->attribute_double = other.attribute_double;
////	*this = other;
//	return *this;
//}

ScalarConverter::~ScalarConverter()
{
}
// =============================================================================

// Convert method ==============================================================
void ScalarConverter::convert(std::string cpp_literal)
{
	std::stringstream ss(cpp_literal);
	ss >> attribute_int;
}
// =============================================================================

// Show values =================================================================
void ScalarConverter::show_values()
{
	std::cout << attribute_int << std::endl;
}
// =============================================================================
