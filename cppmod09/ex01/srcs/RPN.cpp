//
// Created by rdas-nev on 4/13/23.
//

#include "../inc/RPN.hpp"

// Orthodox Canonical Form =====================================================
RPN::RPN()
{
	rpn_sequence = std::stack<std::string>();
	operator1 = 0;
	operator2 = 0;
	operand = 0;
}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN &RPN::operator=(const RPN &other)
{
	this->rpn_sequence = other.rpn_sequence;
	this->operator1 = other.operator1;
	this->operator2 = other.operator2;
	this->operand = other.operand;
	return *this;
}

RPN::~RPN()
{
}
// =============================================================================

// Fill stack ==================================================================
void RPN::fill_stack(std::string input)
{
	std::stringstream ss(input);
	int i = input.size() - 1;

	while (i >= 0)
	{
		while (i >= 0 && input[i] == ' ')
			i--;
		int j = i;
		while (j >= 0 && input[j] != ' ')
			j--;
		rpn_sequence.push(input.substr(j + 1, i - j));
		i = j;
	}
}
// =============================================================================

// Validate ====================================================================
void RPN::isValidInput(std::string input)
{
	int i = 1;
	fill_stack(input);
	int size = rpn_sequence.size();

	while (!rpn_sequence.empty())
	{
		std::string element = rpn_sequence.top();
		if (element.size() > 1)
			throw InputError();
		else if (!(element[0] >= '0' && element[0] <= '9') &&
				 (element[0] != '/') && element[0] != '*' && element[0] != '-' && element[0] != '+')
			throw InputError();
		else if (i == size && (element[0] >= '0' && element[0] <= '9'))
			throw InputError();
		rpn_sequence.pop();
		i++;
	}
}
// =============================================================================

// Calculations ================================================================
bool isOperand(std::string elem)
{
	if (elem[0] == '/' || elem[0] == '*' || elem[0] == '-' || elem[0] == '+')
		return true;
	else
		return false;
}

void RPN::calculate()
{
	if (rpn_sequence.size() < 3)
		throw InputError();
	std::string placeholder = rpn_sequence.top();
	operand = static_cast<int>(placeholder[0]);
	rpn_sequence.pop();

	std::string placeholder2 = rpn_sequence.top();
	std::stringstream ss2(placeholder2);
	ss2 >> operator2;
	rpn_sequence.pop();

	std::string placeholder3 = rpn_sequence.top();
	std::stringstream ss3(placeholder3);
	ss3 >> operator1;
	rpn_sequence.pop();

	int result;
	switch (operand)
	{
		case DIV:
			result = operator1 / operator2;
			break;
		case MUL:
			result = operator1 * operator2;
			break;
		case SUB:
			result = operator1 - operator2;
			break;
		case ADD:
			result = operator1 + operator2;
			break;
	}
	std::ostringstream oss;
	oss << result;
	rpn_sequence.push(oss.str());
}

void RPN::result(std::string input)
{
	std::stringstream ss(input);
	std::string substr;

	while (ss >> substr)
	{
		rpn_sequence.push(substr);
		if (isOperand(rpn_sequence.top()))
			calculate();
	}
	if (rpn_sequence.size() != 1)
		throw InputError();
	std::cout << GREEN << rpn_sequence.top() << RESET << std::endl;
}
// =============================================================================

// Class Exceptions ============================================================
const char *RPN::InputError::what() const throw()
{
	return RED "Error" RESET;
}
// =============================================================================
