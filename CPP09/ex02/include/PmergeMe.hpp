/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:43:54 by mgendrot          #+#    #+#             */
/*   Updated: 2025/02/25 19:25:26 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <iterator>
#include <algorithm>
#include <sstream>



template <typename Container>
class PmergeMe
{
public:
    PmergeMe();
    ~PmergeMe();

    void sort(Container& container);

private:
    void pairAndSort(Container& container);
    void mergeSortPairs(Container& container);
    void generateSequences(Container& container, Container& larger, Container& smaller);
    std::deque<int> generateJacobsthalSequence(size_t size);
    void insertionSort(Container& container, Container& smaller);
    
    typename Container::iterator binarySearch(int value, typename Container::iterator left, typename Container::iterator right);
};

template <typename T>
void print(T lst);


#include "PmergeMe.tpp"




#endif
