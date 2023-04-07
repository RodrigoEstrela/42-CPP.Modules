//
// Created by rdas-nev on 07-04-2023.
//

#include "../inc/Span.hpp"

// Orthodox Canonical Form ====================================================
Span::Span() : storage(0)
{
    max_storage = 0;
    current_storage = 0;
}

Span::Span(Span const &other)
{
    *this = other;
}

Span &Span::operator=(const Span &other)
{
    this->storage = other.storage;
    this->max_storage = other.max_storage;
    this->current_storage = other.current_storage;
    return *this;
}

Span::~Span()
{
}
// ============================================================================

// Constructor with input =====================================================
Span::Span(unsigned int set_max_storage) : storage(0)
{
    max_storage = set_max_storage;
    current_storage = 0;
}
// ============================================================================

// Method to add a number to storage ==========================================
void Span::addNumber(int n)
{
    if (current_storage < max_storage)
    {
        current_storage++;
        storage.push_back(n);
    }
    else
        throw Span::ReachedMaxStorage();
}
// ============================================================================

// Methods to check shortest and longest span =================================
int Span::shortestSpan()
{
    if (current_storage < 2)
        throw Span::NoPossibleSpan();
    std::sort(storage.begin(), storage.end());

    int shortest_span = longestSpan();
    for (unsigned int i = 0; i < storage.size(); i++)
        if (storage[i + 1] - storage[i] < shortest_span && storage[i + 1] - storage[i] >= 0)
            shortest_span = storage[i + 1] - storage[i];
    return shortest_span;
}

int Span::longestSpan()
{
    if (current_storage < 2)
        throw Span::NoPossibleSpan();
    std::sort(storage.begin(), storage.end());
    return (storage.back() - storage.front());
}
// ============================================================================

// Method to add a range of numbers to the container ==========================
void Span::addRangeNumbers(int start, int end)
{
    unsigned int size_to_add = end - start + 1;

    if (current_storage + size_to_add > max_storage)
        throw Span::ReachedMaxStorage();

    current_storage += size_to_add;
    std::vector<int> to_add(size_to_add);

    for (int i = start; i < end; i++)
        to_add.push_back(i);
    storage.insert(storage.end(), to_add.begin(), to_add.end());
}
// ============================================================================

// Method to add random numbers within a range to the container ===============
void Span::addRandomNumbers(int start, long int end, int how_much)
{
    if (current_storage + how_much > max_storage)
        throw Span::ReachedMaxStorage();

    current_storage += how_much;
    std::vector<int> to_add(0);
    srand(time(NULL));

    for (int i = 0; i < how_much; i++)
    {
        int random_number = rand() % (end - start + 1) + start;
        to_add.push_back(random_number);
    }
    storage.insert(storage.end(), to_add.begin(), to_add.end());
}
// ============================================================================

// Class Exceptions ===========================================================
const char *Span::ReachedMaxStorage::what() const throw()
{
    return "Reached maximum number of integers in container.";
}

const char *Span::NoPossibleSpan::what() const throw()
{
    return "No possible span in current vector container.";
}
// ============================================================================
