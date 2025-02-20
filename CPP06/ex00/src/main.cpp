/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 22:27:51 by mgendrot          #+#    #+#             */
/*   Updated: 2025/02/20 22:32:27 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"

int	main(int ac, char **av) {
	if (ac < 2)
	{
		std::cout << "Usage: ./convert [string ...]" << std::endl;
		return (0);
	}
	for (int i = 1; i < ac ; i++)
	{
		std::cout << "\nInput: " << av[i] <<std::endl;
		ScalarConverter::convert(av[i]);
	}

	return 0;
}