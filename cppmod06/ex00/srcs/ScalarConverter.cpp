//
// Created by rdas-nev on 4/3/23.
//

#include <string>
#include "../inc/ScalarConverter.hpp"

// Initialize attributes =======================================================
char	ScalarConverter::_char;
int		ScalarConverter::_int;
float	ScalarConverter::_float;
double	ScalarConverter::_double;
int		ScalarConverter::_checkchar;
int 	ScalarConverter::_checkint;
int 	ScalarConverter::_checkfloat;
// =============================================================================

// Orthodox Canonical Form =====================================================
ScalarConverter::ScalarConverter()
{
	_char = '\0';
	_int = 0;
	_float = 0.0f;
	_double = 0.0;
	_checkchar = 0;
	_checkint = 0;
	_checkfloat = 0;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	this->_char = other._char;
	this->_int = other._int;
	this->_float = other._float;
	this->_double = other._double;
	this->_checkchar = other._checkchar;
	this->_checkint = other._checkint;
	this->_checkfloat = other._checkfloat;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}
// =============================================================================

// Convert methods ==============================================================
void ScalarConverter::convert_from_char(const std::string &str)
{
	_char   = str.c_str()[0];

	// CHAR TO INT -------------------------------------------------------------
	_int    = static_cast<int>(_char);
	// CHAR TO FLOAT -----------------------------------------------------------
	_float  = static_cast<float>(_char);
	// CHAR TO DOUBLE ----------------------------------------------------------
	_double = static_cast<double>(_char);
}

void ScalarConverter::convert_from_int(const std::string &str)
{
	std::stringstream ss(str);
	ss >> _int;

	// INT TO CHAR -------------------------------------------------------------
	if (_int >= 32 && _int <= 127)
		_char   = static_cast<char>(_int);
	else if (_int >= 0 && _int < 32)
		_checkchar = 2;
	else if (_int < 0 || _int > 127)
		_checkchar = 1;
	// INT TO FLOAT ------------------------------------------------------------
	_float  = static_cast<float>(_int);
	// INT TO DOUBLE -----------------------------------------------------------
	_double = static_cast<double>(_int);
}

void ScalarConverter::convert_from_float(const std::string &str)
{
	_float = static_cast<float>(atof(str.c_str()));

	// FLOAT TO CHAR -----------------------------------------------------------
	if (_float >= 32 && _float <= 127)
		_char   = static_cast<char>(_float);
	else if (_float >= 0 && _float < 32)
		_checkchar = 2;
	else if (_float < 0 || _float > 127 || str == "nanf")
		_checkchar = 1;
	// FLOAT TO INT ------------------------------------------------------------
	if (_float > std::numeric_limits<int>::max() ||
	_float < std::numeric_limits<int>::min() || str == "nanf")
		_checkint = 1;
	else
		_int = static_cast<int>(_float);
	// FLOAT TO DOUBLE ---------------------------------------------------------
	_double = static_cast<double>(_float);
}

void ScalarConverter::convert_from_double(const std::string &str)
{
	_double = static_cast<double>(atof(str.c_str()));

	// DOUBLE TO CHAR ----------------------------------------------------------
	if (_double >= 32 && _double <= 127)
		_char   = static_cast<char>(_double);
	else if (_double >= 0 && _double < 32)
		_checkchar = 2;
	else if (_double < 0 || _double > 127 || str == "nan")
		_checkchar = 1;
	// DOUBLE TO INT -----------------------------------------------------------
	if (_double > std::numeric_limits<int>::max() ||
		_double < std::numeric_limits<int>::min() || str == "nan")
		_checkint = 1;
	else
		_int = static_cast<int>(_double);
	// DOUBLE TO FLOAT ---------------------------------------------------------
	if (_double > std::numeric_limits<float>::max() ||
		_double < -std::numeric_limits<int>::max())
		_checkfloat = 1;
	else
		_float = static_cast<float>(_double);
}

void ScalarConverter::convert(std::string const &cpp_literal)
{
	int literal_type = ScalarConverter::getLiteralType(cpp_literal);
	switch (literal_type)
	{
		case CHAR:
			convert_from_char(cpp_literal.substr(1,1));
			break;
		case INT:
			convert_from_int(cpp_literal);
			break;
		case FLOAT:
			convert_from_float(cpp_literal);
			break;
		case DOUBLE:
			convert_from_double(cpp_literal);
			break;
	}
}
// =============================================================================

// Show values =================================================================
void ScalarConverter::show_values()
{
	// CHAR --------------------------------------------------------------------
	if (_checkchar == 1)
		std::cout << "char   | impossible" << std::endl;
	else if (_checkchar == 2)
		std::cout << "char   | Not displayable" << std::endl;
	else
		std::cout << "char   | " << _char << std::endl;
	// INT ---------------------------------------------------------------------
	if (_checkint)
		std::cout << "int    | impossible" << std::endl;
	else
		std::cout << "int    | " << _int << std::endl;
	// FLOAT -------------------------------------------------------------------
	if (_checkfloat)
		std::cout << "float  | impossible" << std::endl;
	else
		std::cout << "float  | " << std::fixed << std::setprecision(1)
		<< _float << "f" << std::endl;
	// DOUBLE ------------------------------------------------------------------
	std::cout << "double | " << std::fixed << std::setprecision(1)
	<< _double << std::endl;
}
// =============================================================================

// Get Literal Type ============================================================
int ScalarConverter::getLiteralType(const std::string &str)
{
	// CHAR --------------------------------------------------------------------
	{
		if (str.length() == 3)
		{
			if (str[0] >= '\'' && str[2] <= '\'')
				return CHAR;
		}
	}
	// INT ---------------------------------------------------------------------
	{
		char *end;
		long int value = strtol(str.c_str(), &end, 10);
		if (*end == '\0')
			if (value >= std::numeric_limits<int>::min() &&
				value <= std::numeric_limits<int>::max())
				return INT;
	}
	// FlOAT -------------------------------------------------------------------
	{
		if (str == "-inff" || str == "+inff" || str == "nanf")
			return FLOAT;
		char *end;
		float value = strtof(str.c_str(), &end);
		if (end != str.c_str())
		{
			if (*end == 'f' && str.substr(str.find('f'), 2)[1] == '\0')
			{
				if (value >= -std::numeric_limits<float>::max() &&
					value <= std::numeric_limits<float>::max())
					return FLOAT;
			}
		}
	}
	// DOUBLE ------------------------------------------------------------------
	{
		if (str == "-inf" || str == "+inf" || str == "nan")
			return DOUBLE;
		char *end;
		double value = strtod(str.c_str(), &end);
		if (end != str.c_str())
		{
			if (*end == '\0')
			{
				if (value >= -std::numeric_limits<double>::max() &&
					value <= std::numeric_limits<double>::max())
					return DOUBLE;
			}
		}
	}
	// invalid input -----------------------------------------------------------
	throw ScalarConverter::InvalidInput();
}
// =============================================================================

// Class Exceptions ============================================================
const char *ScalarConverter::InvalidInput::what() const throw()
{
	return "INVALID INPUT";
}
// =============================================================================
