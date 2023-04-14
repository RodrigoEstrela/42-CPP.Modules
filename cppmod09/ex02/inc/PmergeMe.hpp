//
// Created by rdas-nev on 4/13/23.
//

#ifndef INC_42_CPP_MODULES_PMERGEME_HPP
#define INC_42_CPP_MODULES_PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <deque>
#include <ctime>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define RESET "\033[0m"

bool has_non_digit(const std::string &str);

class PmergeMe
{
	std::vector<int> v_container;
	std::deque<int> d_container;
public:
    // Getters for Containers
		std::vector<int> & get_v_container();
		std::deque<int> &get_d_container();
    // Orthodox Canonical Form
		PmergeMe();
		PmergeMe(PmergeMe const &other);
		PmergeMe &operator=(PmergeMe const &other);
		~PmergeMe();
    // Fill the container and validate it

        template <typename T> bool has_duplicates(const T &cont)
        {
            T sortedArr = cont;
            std::sort(sortedArr.begin(), sortedArr.end());
            return std::unique(sortedArr.begin(), sortedArr.end()) != sortedArr.end();
        }
        template <typename T> bool has_negative(T &cont)
        {
            for (typename T::const_iterator it = cont.begin(); it != cont.end(); ++it)
                if (*it <= 0)
                    return true;
            return false;
        }
        template <typename T> void fill_container_from_args(int ac, char **av, T &cont)
        {
            for (int i = 1; i < ac; i++)
            {
                std::istringstream iss(av[i]);
                int n;
                if (!(iss >> n) || has_non_digit(av[i]))
					throw PmergeMe::InvalidArgument();
                cont.push_back(n);
            }
            if (has_duplicates(cont))
                throw HasDuplicate();
            if (has_negative(cont))
                throw HasNegative();
        }
    // Insertion Sort
        template<typename  T> void insertion_sort(T &cont, int start, int end)
        {
            for (int i = start + 1; i <= end; i++)
            {
                int key = cont[i];
                int j = i - 1;

                while (j >= start && cont[j] > key)
                {
					cont[j + 1] = cont[j];
                    j--;
                }
				cont[j + 1] = key;
            }
        }
    // Algorithm For Vector Container
        void v_merge_insert_sort(int start, int end);
        void v_merge_insert_sort();
    // Algorithm For Deque Container
        void d_merge_insert_sort(int start, int end);
        void d_merge_insert_sort();
	// Class Exceptions
        class InvalidArgument : public std::exception
        {
            public:
                const char *what() const throw();
        };
        class HasDuplicate : public std::exception
        {
            public:
                const char *what() const throw();
        };
        class HasNegative : public std::exception
        {
            public:
                const char *what() const throw();
        };
};

#endif //INC_42_CPP_MODULES_PMERGEME_HPP
