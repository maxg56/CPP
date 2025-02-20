/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:58:16 by mgendrot          #+#    #+#             */
/*   Updated: 2025/02/20 21:50:43 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:42:55 by mgendrot          #+#    #+#             */
/*   Updated: 2025/02/20 20:52:08 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("Robotomy Request", 72, 45), _target("UNKNOWN")
{
	std::cout << "[C] RobotomyRequestForm default constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) 
	: AForm("Robotomy Request", 72, 45), _target(target) 
{
	std::cout << "[C] RobotomyRequestForm constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) 
	: AForm(src.getName(), src.getSignGrade(),src.getExecuteGrade()), _target(src.getTarget()) 
{
	std::cout << "[C] RobotomyRequestForm copy constructor called." << std::endl;
	*this = src;
}

RobotomyRequestForm &	RobotomyRequestForm::operator=(RobotomyRequestForm const &other) 
{
	if (this != &other) 
	{
		this->_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() 
{
	std::cout << "[D] RobotomyRequestForm default destructor called." << std::endl;
}

std::ostream &	operator<<(std::ostream & o, RobotomyRequestForm const &other) 
{
	o << other.getName() << ", form signed : " << 
	(other.getSigned() ? "true" : "false") << 
	", target : " << other.getTarget();
	return o;
}

std::string		RobotomyRequestForm::getTarget() const { return _target; }

static int robot_fail = 0;

void	RobotomyRequestForm::execute(Bureaucrat const &executor)const
{
	if ((int)executor.getGrade() > this->getExecuteGrade())
		throw (Bureaucrat::GradeTooLowException());
	else if (this->getSigned() == false)
		throw (AForm::FormNotSignedException());
	else if (robot_fail++ % 2)
		std::cout << "BRRRRRRRRRRRRRR\n" << this->getTarget() << " was robotomized" << std::endl;
	else
		std::cout << "Robotomy failed" << std::endl;
}

