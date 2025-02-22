/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:17:32 by mgendrot          #+#    #+#             */
/*   Updated: 2025/02/22 17:35:52 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main() 
{
    std::vector<int> arr;

	for (int i = 0; i < _4;i++)
		arr.push_back(i);
    try 
	{
        std::cout << easyfind(arr, 3) << std::endl;  // Should print 3
        std::cout << easyfind(arr, 90000) << std::endl;  // Should throw exception
    }
    catch (const NoValueException& e) 
	{
        std::cout << e.what() << std::endl;  // Should print "No value in array"
    }

    return 0;
}