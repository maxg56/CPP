/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:14:46 by mgendrot          #+#    #+#             */
/*   Updated: 2025/02/26 23:33:36 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP


#include <string>
#include <iostream>
#include <deque>
#include <vector>
#include <list>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <ctime>
#include <iomanip>
#include <typeinfo>

#define CLOCK_TO_US(clock) double(clock) / double(CLOCKS_PER_SEC) * 1e+6

template <typename Container>
class PmergeMe 
{   
    Container container;
     public:
        typedef typename Container::value_type ValueType;
        typedef typename Container::iterator Iterator;
        
        PmergeMe();
        PmergeMe(char **av);
        void sort_time();
        void sort();
        
        typename Container::iterator begin();
        typename Container::iterator end();
   
    private:
        clock_t start_;
        clock_t end_;
        
        clock_t     _time();
        int         _Jacobsthal(int k);
        size_t      _count_word_and_check(std::string &str);    
        void        _sort(Container &vec);
        std::string _container_type();
        void        _insert(Container &main, Container &pend, ValueType odd, Container &left, \
                            Container &vec, bool is_odd, int order);
    
   
};

template <typename Container>
std::ostream& operator<<(std::ostream &os, const PmergeMe<Container> &obj);

#include "PmergeMe.tpp"

#endif
