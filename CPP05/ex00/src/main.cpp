/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:22:54 by mgendrot          #+#    #+#             */
/*   Updated: 2025/02/21 17:44:35 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"

int	main() 
{
	Bureaucrat *	Donald = NULL;
	Bureaucrat *	Joe = NULL;

	try 
	{
		Donald = new Bureaucrat("Donald", 2);
		Donald->promote();
		std::cout << *Donald << std::endl;
	}
	catch (const std::exception& e) 
	{
		std::cerr << "\033[33m[0] Incrementing grade of " << "Donald" <<
			" failed: " << e.what() << "\033[0m" << std::endl;
	}
	try
	{
		Joe = new Bureaucrat("Joe",122);
		Joe->demote();
		std::cout << *Joe << std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cerr << "\033[33m[1] Incrementing grade of " << Joe->getName() <<
		" failed: " << e.what() << "\033[0m" << std::endl;
	}
	delete Joe;
	delete Donald;
}