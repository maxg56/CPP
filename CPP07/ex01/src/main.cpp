/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:47:09 by mgendrot          #+#    #+#             */
/*   Updated: 2025/02/22 15:52:32 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"iter.hpp"

int main() 
{
    // Testing with an array of integers
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArraySize = sizeof(intArray) / sizeof(intArray[0]);
    std::cout << "Integer array: ";
    iter(intArray, intArraySize, &printValue<int>);
    std::cout << std::endl;

    // Testing with an array of doubles
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4};
    size_t doubleArraySize = sizeof(doubleArray) / sizeof(doubleArray[0]);
    std::cout << "Double array: ";
    iter(doubleArray, doubleArraySize, &printValue<double>);
    std::cout << std::endl;

    // Testing with an array of strings
    std::string stringArray[] = {"Hello", "World", "C++"};
    size_t stringArraySize = sizeof(stringArray) / sizeof(stringArray[0]);
    std::cout << "String array: ";
    iter(stringArray, stringArraySize, printValue<std::string>);
    std::cout << std::endl;

    return 0;
}