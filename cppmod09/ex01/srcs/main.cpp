//
// Created by rdas-nev on 4/13/23.
//

#include "../inc/RPN.hpp"

int main(int ac, char **av)
{
	try
	{
		if (ac == 2)
		{
			std::string input = av[1];
			RPN calculate;

			calculate.isValidInput(input);
			calculate.result(input);
		}
		else
			throw RPN::InputError();
	}
	catch (RPN::InputError &e)
	{
		std::cout << e.what() << std::endl;
	}
}
