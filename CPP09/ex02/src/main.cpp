/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:43:33 by mgendrot          #+#    #+#             */
/*   Updated: 2025/02/25 19:37:09 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <vector>
#include <deque>
#include <iostream>
#include <sstream>

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <list of integers>\n";
        return 1;
    }

    std::vector<int> numbers;
    std::list<int> numbers_list;
    for (int i = 1; i < argc; ++i)
    {
        std::istringstream iss(argv[i]);
        int num;
        if (!(iss >> num))
        {
            std::cerr << "Invalid input: " << argv[i] << "\n";
            return 1;
        }
        numbers.push_back(num);
        numbers_list.push_back(num);
    }

    PmergeMe<std::vector<int> > sorter;
    PmergeMe<std::list<int> > sorterlist;
    
    sorter.sort(numbers);
    //sorterlist.sort(numbers_list);
    
    std::cout << "Sorted: ";
    for (size_t i = 0; i < numbers.size(); ++i)
        std::cout << numbers[i] << " ";
    std::cout << std::endl;

    return 0;
}
