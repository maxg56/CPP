/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:22:54 by mgendrot          #+#    #+#             */
/*   Updated: 2025/02/20 18:24:05 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main() {
	Bureaucrat *	Donald = NULL;
	Bureaucrat *	Joe = NULL;
	Form *			simpleDoc = NULL;

	try {
		Donald = new Bureaucrat("Donald", 55);
		Joe = new Bureaucrat("Joe", 35);
		simpleDoc = new Form("Simple Document", 100);
		simpleDoc->beSigned(*Donald);
		delete simpleDoc;
		simpleDoc = new Form("Simple", 100);
		simpleDoc->beSigned(*Joe);
		simpleDoc->beSigned(*Joe);
	}
	catch (const std::exception& e) 
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << *simpleDoc << std::endl;
	delete Donald;
	delete Joe;
	delete simpleDoc;
}