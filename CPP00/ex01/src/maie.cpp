/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maie.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 09:56:30 by max               #+#    #+#             */
/*   Updated: 2025/02/06 10:26:34 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "contace.hpp"
#include <iostream>
#include <stdlib.h>



int	main() {
	PhoneBook	PhoneBook;
	std::string		line;
	std::string			add = "ADD";
	std::string			search = "SEARCH";
	std::string			exit = "EXIT";
	
	system("clear");
	std::cout << "Hello ! Welcome to your new contact manager." << std::endl;
	while (1)
	{
		std::cout << "Type ADD, SEARCH or EXIT : ";
		std::getline(std::cin, line);
		if (!line.compare(add))
			PhoneBook.add_contact();
		else if (!line.compare(search))
			PhoneBook.search_contact();
		else if (!line.compare(exit))
		{
			std::cout << "Goodbye !" << std::endl;
			break;
		}
		system("clear");
	}
	return 0;
}
