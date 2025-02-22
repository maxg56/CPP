/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:22:54 by mgendrot          #+#    #+#             */
/*   Updated: 2025/02/22 14:33:50 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main() {
	Bureaucrat *	Donald = NULL;
	Bureaucrat *	Joe = NULL;
	Form *			simpleDoc = NULL;

	try 
	{
		Donald = new Bureaucrat("Donald", 55);
		Joe = new Bureaucrat("Joe", 35);
		simpleDoc = new Form("Simple Document", 0);
		simpleDoc->beSigned(*Donald);
		delete simpleDoc;
	}
	catch (const std::exception& e) 
	{
		std::cerr << "[1] " << e.what() << '\n';
	}
	try
	{
		simpleDoc = new Form("Simple", 44);
		simpleDoc->beSigned(*Joe);
		simpleDoc->beSigned(*Joe);
	}
	catch(const std::exception& e)
	{
		std::cerr << "[2]" << e.what() << '\n';
	}
	
	std::cout << *simpleDoc << std::endl;
	delete Donald;
	delete Joe;
	delete simpleDoc;
}