//
// Created by rdas-nev on 4/11/23.
//

#include "../inc/BitcoinExchange.hpp"

int main(int ac, char **av)
{
	try
	{
		if (ac == 2)
		{
			BitcoinExchange btc_exc;
			btc_exc.get_value(av[1]);
		}
		else
			throw BitcoinExchange::CouldntOpenFile();
	}
	catch (BitcoinExchange::CouldntOpenFile &e)
	{
		std::cout << e.what() << std::endl;
	}
}
