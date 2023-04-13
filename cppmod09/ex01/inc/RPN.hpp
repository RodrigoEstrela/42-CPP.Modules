//
// Created by rdas-nev on 4/13/23.
//

#ifndef INC_42_CPP_MODULES_RPN_HPP
#define INC_42_CPP_MODULES_RPN_HPP

#include <stack>
#include <iostream>
#include <sstream>
#include <cstdlib>

enum
{
	DIV = 47,
	MUL = 42,
	SUB = 45,
	ADD = 43
};

class RPN
{
		std::stack<std::string> rpn_sequence;
		int operator1,
			operator2,
			operand;
	public:
	// Orthodox Canonical Form
		RPN();
		RPN(RPN const &other);
		RPN &operator=(RPN const &other);
		~RPN();
	// Fill Stack
		void fill_stack(std::string input);
	// Validate
		void isValidInput(std::string input);
	// Calculations
		void calculate();
		void result(std::string input);
	// Class Exceptions
	class InputError : public std::exception
	{
		public:
			const char *what() const throw();
	};
};


#endif //INC_42_CPP_MODULES_RPN_HPP
