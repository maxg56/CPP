/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 21:03:40 by mgendrot          #+#    #+#             */
/*   Updated: 2025/02/20 21:50:56 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("Presidential Pardon", 25, 5), _target("UNKNOWN")
{
	std::cout << "[C] PresidentialPardonForm default constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) 
	: AForm("Presidential Pardon", 25, 5), _target(target)
{
	std::cout << "[C] PresidentialPardonForm constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) 
	: AForm(src.getName(), src.getSignGrade(),src.getExecuteGrade()), _target(src.getTarget()) 
{
	std::cout << "[C] PresidentialPardonForm copy constructor called." << std::endl;
	*this = src;
}

PresidentialPardonForm &	PresidentialPardonForm::operator=(PresidentialPardonForm const &other) 
{
	if (this != &other) 
	{
		this->_target = other._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() 
{
	std::cout << "[D] PresidentialPardonForm default destructor called." << std::endl;
}

std::ostream &	operator<<(std::ostream & o, PresidentialPardonForm const &other) 
{
	o << other.getName() << ", form signed : " << 
	(other.getSigned() ? "true" : "false") <<
	", target : " << other.getTarget();
	return o;
}

std::string		PresidentialPardonForm::getTarget() const { return _target; }

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if ((int)executor.getGrade() > this->getExecuteGrade())
		throw (Bureaucrat::GradeTooLowException());
	else if (this->getSigned() == false)
		throw (AForm::FormNotSignedException());
	else
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
