/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 21:06:53 by mgendrot          #+#    #+#             */
/*   Updated: 2025/02/22 14:35:53 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main() {
	Bureaucrat *	Donald = new Bureaucrat("Donald", 1);
	Bureaucrat *	Joe = new Bureaucrat("Joe", 10);
	Bureaucrat *	Miguel = new Bureaucrat("Miguel", 65);
	AForm *			shru = new ShrubberyCreationForm("home");
	AForm *			robot = new RobotomyRequestForm("robot");
	AForm *			pres = new PresidentialPardonForm("president");
	std::cout << "\n";
	try
	{
		shru->beSigned(*Miguel);
		robot->beSigned(*Joe);
		pres->beSigned(*Donald);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
		std::cout << "\n";
	try {
		robot->execute(*Donald);
		shru->execute(*Donald);
		pres->execute(*Donald);
		robot->execute(*Donald);
	}
	catch(const AForm::FormSignedException::exception& e) {
		std::cerr << e.what()  <<'\n';
	}
	std::cout << "\n";
	std::cout << *shru << std::endl;
	std::cout << *robot << std::endl;
	std::cout << "\n";
	delete robot;
	delete shru;
	delete pres;
	delete Miguel;
	delete Joe;
	delete Donald;
}
