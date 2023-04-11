//
// Created by rdas-nev on 07-04-2023.
//

#include "../inc/Span.hpp"

int main()
{
    // Container empty or only one member -------------------------------------
	{
		try
		{
			Span sp = Span(1);
			sp.addNumber(42); // COMENT THIS LINE TO TEST EMPTY VECTOR
//			sp.addNumber(41); // deCOMENT THIS LINE TO TEST MORE THAN MAX

			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
    // Using simple addNumber method ------------------------------------------
	{
		try
		{
			Span sp = Span(5);
			sp.addNumber(6);
			// COMMENT THE REST OF THE NUMBERS TO CATCH EXCEPTION
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			// ADD MORE NUMBERS TO CATCH EXCEPTION
//		sp.addNumber(42);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
    // Using range insertion method -------------------------------------------
	{
		try
		{
			Span sp = Span(500);
			// Change range to catch exceptions
			sp.addRangeNumbers(3, 47);

			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
    // Using random numbers from range insertion method -----------------------
	{
		try
		{
			Span sp = Span(10000);
			// Change how much numbers to catch exceptions
			sp.addRandomNumbers(1, 100000000000, 10000);

			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}
