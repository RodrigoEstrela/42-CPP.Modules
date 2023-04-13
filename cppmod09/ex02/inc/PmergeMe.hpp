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

class PmergeMe
{
	public:
    // Containers
        std::vector<int> v_container;
        std::deque<int> d_container;
    // Orthodox Canonical Form
		PmergeMe();
		PmergeMe(PmergeMe const &other);
		PmergeMe &operator=(PmergeMe const &other);
		~PmergeMe();
    // Fill the container and validate it
        template <typename T> bool has_duplicates(const T &arr)
        {
            T sortedArr = arr;
            std::sort(sortedArr.begin(), sortedArr.end());
            return std::unique(sortedArr.begin(), sortedArr.end()) != sortedArr.end();
        }
        template <typename T> bool has_negative(T &arr)
        {
            for (typename T::const_iterator it = arr.begin(); it != arr.end(); ++it)
                if (*it <= 0)
                    return true;
            return false;
        }
        template <typename T> void fill_array_from_args(int ac, char **av, T &arr)
        {
            for (int i = 1; i < ac; i++)
            {
                std::istringstream iss(av[i]);
                int n;
                if (!(iss >> n))
                    throw PmergeMe::InvalidArgument();
                arr.push_back(n);
            }
            if (has_duplicates(arr))
                throw HasDuplicate();
            if (has_negative(arr))
                throw HasNegative();
        }
    // Insertion Sort
        template<typename  T> void insertion_sort(T &arr, int start, int end)
        {
            for (int i = start + 1; i <= end; i++)
            {
                int key = arr[i];
                int j = i - 1;

                while (j >= start && arr[j] > key)
                {
                    arr[j + 1] = arr[j];
                    j--;
                }
                arr[j + 1] = key;
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
