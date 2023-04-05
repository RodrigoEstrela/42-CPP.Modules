//
// Created by rdas-nev on 4/5/23.
//

#include "../inc/Array.hpp"

int main()
{
	Array<int> arr(5);
	for (unsigned int i = 0; i < arr.size(); i++)
		arr[i] = i;
	for (unsigned int i = 0; i < arr.size(); i++)
		std::cout << arr[i] << std::endl;
	return 0;
}
