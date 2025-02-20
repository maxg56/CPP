/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:22:54 by mgendrot          #+#    #+#             */
/*   Updated: 2025/02/20 15:25:37 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"

int	main() 
{
	Bureaucrat *	Donald = NULL;
	Bureaucrat *	Joe = NULL;

	try 
	{
		Donald = new Bureaucrat("Donald", 5);
		Donald->promote();
	}
	catch (const std::exception& e) 
	{
		std::cerr << e.what() << '\n';
	}
	Joe = new Bureaucrat(*Donald);
	std::cout << *Donald << std::endl;
	std::cout << *Joe << std::endl;
	delete Donald;
}