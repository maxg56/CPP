/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:42:55 by mgendrot          #+#    #+#             */
/*   Updated: 2025/02/20 21:51:03 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("Shrubbery Creation", 145, 137), _target("UNKNOWN")
{
	std::cout << "[C] ShrubberyCreationForm default constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) 
	: AForm("Shrubbery Creation", 145, 137), _target(target) 
{
	std::cout << "[C] ShrubberyCreationForm constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) 
	: AForm(src.getName(), src.getSignGrade(),src.getExecuteGrade()), _target(src.getTarget()) 
{
	std::cout << "[C] ShrubberyCreationForm copy constructor called." << std::endl;
	*this = src;
}

ShrubberyCreationForm &	ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other) 
{
	if (this != &other) 
	{
		this->_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() 
{
	std::cout << "[D] ShrubberyCreationForm default destructor called." << std::endl;
}

std::ostream &	operator<<(std::ostream & o, ShrubberyCreationForm const &other) 
{
	o << other.getName() << ", form signed : " << (other.getSigned() ? "true" : "false") \
		<< ", target : " << other.getTarget();
	return o;
}

std::string		ShrubberyCreationForm::getTarget() const { return _target; }

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > getExecuteGrade())
		throw AForm::GradeTooLowException();
	else if (!getSigned())
		throw AForm::FormNotSignedException();
	else
	{
		std::ofstream outfile (this->getTarget().append("_shrubbery").c_str());

		for (int i = 0; i < 5; i++)
		{
			outfile <<
			"         v" << std::endl <<
			"        >X<" << std::endl <<
			"         A" << std::endl <<
			"        d$b" << std::endl <<
			"      .d\\$$b." << std::endl <<
			"    .d$i$$\\$$b." << std::endl <<
			"       d$$@b" << std::endl <<
			"      d\\$$$ib" << std::endl <<
			"    .d$$$\\$$$b" << std::endl <<
			"  .d$$@$$$$\\$$ib." << std::endl <<
			"      d$$i$$b" << std::endl <<
			"     d\\$$$$@$b" << std::endl <<
			"  .d$@$$\\$$$$$@b." << std::endl <<
			".d$$$$i$$$\\$$$$$$b." << std::endl <<
			"        ###" << std::endl <<
			"        ###" << std::endl <<
			"        ###" << std::endl <<
		std::endl;
		}
		outfile.close();
	}
}

	