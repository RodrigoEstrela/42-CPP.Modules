//
// Created by rdas-nev on 07-04-2023.
//

#ifndef INC_42_CPP_MODULES_SPAN_HPP
#define INC_42_CPP_MODULES_SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>

class Span
{
    // Attributes
        std::vector<int> storage;
        unsigned int max_storage;
        unsigned int current_storage;
    public:
    // Orthodox Canonical Form
        Span();
        Span(Span const &other);
        Span &operator=(Span const &other);
        ~Span();
    // Constructor with input
        Span(unsigned int set_max_storage);
    // Method to add a number to storage
        void addNumber(int n);
    // Methods to check shortest and longest span
        int shortestSpan();
        int longestSpan();
    // Method to add a range of numbers to the container
        void addRangeNumbers(int start, int end);
    // Method to add random numbers within a range to the container
        void addRandomNumbers(int start, long int end, int how_much);
    // Class Exceptions
        class ReachedMaxStorage : std::exception
        {
            public:
                const char *what() const throw();
        };
        class NoPossibleSpan : std::exception
        {
            public:
                const char *what() const throw();
        };
};

#endif //INC_42_CPP_MODULES_SPAN_HPP
