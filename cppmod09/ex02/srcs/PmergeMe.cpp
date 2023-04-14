//
// Created by rdas-nev on 4/13/23.
//

#include "../inc/PmergeMe.hpp"

// Getters for containers =====================================================
std::vector<int> & PmergeMe::get_v_container()
{
	return v_container;
}

std::deque<int> &PmergeMe::get_d_container()
{
	return d_container;
}
// ============================================================================

// Orthodox Canonical Form ====================================================
PmergeMe::PmergeMe()
{
    v_container = std::vector<int>();
    d_container = std::deque<int>();
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    this->v_container = other.v_container;
    this->d_container = other.d_container;
    return *this;
}

PmergeMe::~PmergeMe()
{
}
// ============================================================================

// Algorithm For Vector Container =============================================
void PmergeMe::v_merge_insert_sort(int start, int end)
{
    if (start >= end)
        return;
    if (end - start + 1 <= 16)
    {
        insertion_sort(v_container, start, end);
        return;
    }
    int mid = start + (end - start) / 2;
    v_merge_insert_sort(start, mid);
    v_merge_insert_sort(mid+1, end);
    std::vector<int> temp(end - start + 1);
    int i = start, j = mid+1, k = 0;
    while (i <= mid && j <= end)
    {
        if (v_container[i] <= v_container[j])
            temp[k++] = v_container[i++];
        else
            temp[k++] = v_container[j++];
    }
    while (i <= mid)
        temp[k++] = v_container[i++];
    while (j <= end)
        temp[k++] = v_container[j++];
    for (int l = 0; l < k; l++)
        v_container[start + l] = temp[l];
}

void PmergeMe::v_merge_insert_sort()
{
    v_merge_insert_sort(0, (int)v_container.size() - 1);
}
// ============================================================================

// Algortihm For Deque Container ==============================================
void PmergeMe::d_merge_insert_sort(int start, int end)
{
    if (end - start <= 1) {
        return;
    }
    if (end - start <= 8) {
        insertion_sort(d_container, start, end);
        return;
    }
    int mid = (start + end) / 2;
    d_merge_insert_sort(start, mid);
    d_merge_insert_sort(mid, end);
    std::deque<int>::iterator it1 = d_container.begin() + start;
    std::deque<int>::iterator it2 = d_container.begin() + mid;
    while (it1 != d_container.begin() + mid && it2 != d_container.begin() + end)
    {
        if (*it1 < *it2)
        {
            it1++;
        }
        else
        {
            int value = *it2;
            d_container.erase(it2);
            d_container.insert(it1, value);
            it1++;
            it2++;
            mid++;
        }
    }
}

void PmergeMe::d_merge_insert_sort()
{
    d_merge_insert_sort(0, (int)d_container.size() - 1);
}
// ============================================================================

// Class Exceptions ===========================================================
const char *PmergeMe::InvalidArgument::what() const throw()
{
    return RED "Error: invalid argument." RESET;
}

const char *PmergeMe::HasDuplicate::what() const throw()
{
    return RED "Error: has duplicates." RESET;
}

const char *PmergeMe::HasNegative::what() const throw()
{
    return RED "Error: has negative number." RESET;
}
// ============================================================================
