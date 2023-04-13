//
// Created by rdas-nev on 4/13/23.
//

#include "../inc/PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac >= 3)
    {
        PmergeMe sorter;
        try
        {
            // Input --------------------------------------------------------
            std::vector<int> input;
            sorter.fill_array_from_args(ac, av, input);
            std::cout << "Original array: ";
            for (int i = 0; i < (int)input.size(); i++)
                std::cout << input[i] << " ";
            std::cout << std::endl;
            // Vector Container ---------------------------------------------
            std::clock_t start = std::clock();
            sorter.fill_array_from_args(ac, av, sorter.v_container);
            sorter.v_merge_insert_sort();
            std::clock_t end = std::clock();
            // Printing Sorted ---------------------------------------------
            std::cout << "Sorted array: ";
            for (int i = 0; i < (int)sorter.v_container.size(); i++)
                std::cout << sorter.v_container[i] << " ";
            std::cout << std::endl;
            // Deque Container ----------------------------------------------
            std::clock_t startd = std::clock();
            sorter.fill_array_from_args(ac, av, sorter.d_container);
            sorter.d_merge_insert_sort();
            std::clock_t endd = std::clock();
            // Printing Times ------------------------------------------------
            std::cout << "Vector: " << (end - start) * 1000000 / CLOCKS_PER_SEC << " microseconds" << std::endl;
            std::cout << "Deque: " << (endd - startd) * 1000000 / CLOCKS_PER_SEC << " microseconds" << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    else
    {
        std::cout << "Insufficient arguments." << std::endl;
        return 1;
    }
}
