/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 21:06:53 by mgendrot          #+#    #+#             */
/*   Updated: 2025/02/20 22:11:38 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Intern.hpp"

int main() 
{
	Bureaucrat bob = Bureaucrat("Bob", 1);
    Intern someRandomIntern;
    AForm* rrf;

    rrf = someRandomIntern.makeForm("PresidentialPardonForm", "Bender");
    if (rrf)
	{
		rrf->beSigned(bob);
        delete rrf;
	}

    rrf = someRandomIntern.makeForm("unknown form", "Target");
	if (rrf)
   	{
		rrf->beSigned(bob);
        delete rrf;
	}
    return 0;
}

