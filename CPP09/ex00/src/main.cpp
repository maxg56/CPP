/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxence <maxence@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:40:24 by mgendrot          #+#    #+#             */
/*   Updated: 2025/02/24 22:45:14 by maxence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"



int main(int ac , char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return 0;	
	}
	BitcoinExchange exchange(av[1]);
	
	
	
}