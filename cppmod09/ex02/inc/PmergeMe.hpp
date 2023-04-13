//
// Created by rdas-nev on 4/13/23.
//

#ifndef INC_42_CPP_MODULES_PMERGEME_HPP
#define INC_42_CPP_MODULES_PMERGEME_HPP

#include <ctime>
#include <iostream>
#include <vector>
#include <deque>

class PmergeMe
{
		std::vector<int> v_container;
		std::deque<int> d_container;
	public:
	// Orthodox Canonical Form
		PmergeMe();
		PmergeMe(PmergeMe const &other);
		PmergeMe &operator=(PmergeMe const &other);
		~PmergeMe();
	
};


#endif //INC_42_CPP_MODULES_PMERGEME_HPP
