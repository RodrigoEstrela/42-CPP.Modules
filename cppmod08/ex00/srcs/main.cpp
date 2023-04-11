//
// Created by rdas-nev on 07-04-2023.
//

#include "../inc/easyfind.hpp"

int main()
{
    // fill the vector container ----------------------------------------------
    std::vector<int> v;
    for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	// print the vector container ---------------------------------------------
	std::cout << "Vector container: ";
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
    // try block --------------------------------------------------------------
    try
    {
        std::cout << *easyfind(v, 0) << std::endl; // value exists in vector container
        std::cout << *easyfind(v, 10) << std::endl; // value does not exist in vector container
    }
    // catch block ------------------------------------------------------------
    catch (std::exception &e)
    {
        (void)e;
        std::cout << "Value not found on vector." << std::endl;
    }
    return 0;
}
