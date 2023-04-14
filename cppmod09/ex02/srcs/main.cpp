//
// Created by rdas-nev on 4/13/23.
//

#include "../inc/PmergeMe.hpp"

bool has_non_digit(const std::string &str)
{
	return (str.find_first_not_of("0123456789") != std::string::npos);
}

int main(int ac, char **av)
{
    if (ac >= 3)
    {
        PmergeMe sorter;
        try
        {
            // Input --------------------------------------------------------
            std::vector<int> input;
			sorter.fill_container_from_args(ac, av, input);
            std::cout << YELLOW "Original array: " RESET;
            for (int i = 0; i < (int)input.size(); i++)
                std::cout << input[i] << " ";
            std::cout << std::endl;
            // Vector Container ---------------------------------------------
            std::clock_t start = std::clock();
			sorter.fill_container_from_args(ac, av, sorter.get_v_container());
            sorter.v_merge_insert_sort();
            std::clock_t end = std::clock();
            // Printing Sorted ---------------------------------------------
            std::cout << GREEN "Sorted array: " RESET;
            for (int i = 0; i < (int)sorter.get_v_container().size(); i++)
                std::cout << sorter.get_v_container()[i] << " ";
            std::cout << std::endl;
            // Deque Container ----------------------------------------------
            std::clock_t startd = std::clock();
			sorter.fill_container_from_args(ac, av, sorter.get_d_container());
            sorter.d_merge_insert_sort();
            std::clock_t endd = std::clock();
            // Printing Times ------------------------------------------------
			std::cout << BLUE "Time to process a range of " RESET << input.size() << BLUE " elements with std::vector : " RESET
			<< (end - start) * 1000000 / CLOCKS_PER_SEC << BLUE " microseconds" RESET << std::endl;
			std::cout << BLUE "Time to process a range of " RESET << input.size() << BLUE " elements with std::deque : " RESET
			<< (endd - startd) * 1000000 / CLOCKS_PER_SEC << BLUE " microseconds" RESET << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    else
    {
        std::cout << RED "Insufficient arguments." RESET << std::endl;
        return 1;
    }
}
