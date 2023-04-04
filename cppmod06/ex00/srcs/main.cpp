//
// Created by rdas-nev on 4/3/23.
//

#include "../inc/ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		try
		{
			ScalarConverter::convert((std::string)av[1]);
			ScalarConverter::show_values();
		}
		catch (ScalarConverter::InvalidInput &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	else
	{
		std::cout << "Please provide one argument." << std::endl;
	}
}
