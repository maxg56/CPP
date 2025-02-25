#ifndef PMERGEME_TPP
#define PMERGEME_TPP

#include "PmergeMe.hpp"

template <typename Container>
PmergeMe<Container>::PmergeMe() {}

template <typename Container>
PmergeMe<Container>::~PmergeMe() {}

template <typename Container>
void PmergeMe<Container>::sort(Container& container)
{
    if (container.size() <= 1)
        return;

    pairAndSort(container);
    mergeSortPairs(container);

    Container larger, smaller;
    generateSequences(container, larger, smaller);

    insertionSort(larger, smaller);
    container = larger;
}

template <typename Container>
void PmergeMe<Container>::pairAndSort(Container& container)
{
    typename Container::iterator it = container.begin();
    while (it != container.end())
    {
        typename Container::iterator next_it = it;
        std::advance(next_it, 1);
        if (next_it != container.end() && *it > *next_it)
            std::iter_swap(it, next_it);
        std::advance(it, 2);
    }
}

template <typename Container>
void PmergeMe<Container>::mergeSortPairs(Container& container)
{
    std::sort(container.begin(), container.end());
}

template <typename Container>
void PmergeMe<Container>::generateSequences(Container& container, Container& larger, Container& smaller)
{
    typename Container::iterator it = container.begin();
    while (it != container.end())
    {
        typename Container::iterator next_it = it;
        std::advance(next_it, 1);
        if (next_it != container.end())
        {
            larger.push_back(*next_it);
            smaller.push_back(*it);
            std::advance(it, 2);
        }
        else
        {
            larger.push_back(*it);
            break;
        }
    }
}

template <typename Container>
std::deque<int> PmergeMe<Container>::generateJacobsthalSequence(size_t size)
{
    std::deque<int> seq;
    seq.push_back(0);
    seq.push_back(1);
    while (seq.back() < static_cast<int>(size))
        seq.push_back(seq.back() + 2 * seq[seq.size() - 2]);
    return seq;
}

template <typename Container>
void PmergeMe<Container>::insertionSort(Container& container, Container& smaller)
{
    std::deque<int> jacobsthal = generateJacobsthalSequence(smaller.size());
    for (size_t i = 1; i < jacobsthal.size() && static_cast<size_t>(jacobsthal[i]) <= smaller.size(); ++i)
    {
        size_t j = static_cast<size_t>(jacobsthal[i]);
        while (j > static_cast<size_t>(jacobsthal[i - 1]))
        {
            if (j <= smaller.size())
            {
                typename Container::iterator pos = binarySearch(smaller[j - 1], container.begin(), container.end());
                container.insert(pos, smaller[j - 1]);
            }
            --j;
        }
    }
}

template <typename Container>
typename Container::iterator PmergeMe<Container>::binarySearch(int value, typename Container::iterator left, typename Container::iterator right)
{
    typename Container::iterator mid;
    while (std::distance(left, right) > 1)
    {
        mid = left;
        std::advance(mid, std::distance(left, right) / 2);
        if (value > *mid)
            left = mid;
        else
            right = mid;
    }
    if (value > *left)
    {
        typename Container::iterator next_left = left;
        std::advance(next_left, 1);
        return next_left;
    }
    return left;
}

#endif
