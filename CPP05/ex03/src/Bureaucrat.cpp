/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:25:52 by mgendrot          #+#    #+#             */
/*   Updated: 2025/02/21 16:20:21 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() :_name("UNKNOWN") ,_grade(0) 
{
	std::cout << "[C] Bureaucrat default constructor called." << std::endl;
}


Bureaucrat::Bureaucrat(std::string const name, int grade) 
	: 	_name(name), _grade(grade)
{
	std::cout << "[C] Bureaucrat constructor called." << std::endl;
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) 
	: _name(src.getName()), _grade(src.getGrade()) 
{
	std::cout << "[C] Bureaucrat copy constructor called." << std::endl;
	*this = src;
}

Bureaucrat::~Bureaucrat() 
{
	std::cout << "[D] Bureaucrat default destructor called." << std::endl;
}

Bureaucrat &	Bureaucrat::operator=(Bureaucrat const &other) 
{
	if (this != &other) 
	{
		this->_grade = other._grade;
	}
	return *this;
}

std::ostream &	operator<<(std::ostream & o, Bureaucrat const &other) 
{
	o << other.getName() << ", bureaucrat grade : " << other.getGrade();
	return o;
}


std::string		Bureaucrat::getName() const { return _name; }
int				Bureaucrat::getGrade() const { return _grade; }

void			Bureaucrat::promote() 
{
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade--;
}

void			Bureaucrat::demote() 
{
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade++;
}

void			Bureaucrat::signForm(std::string name, bool sign)
{
	if (sign)
		std::cout << _name << " signs " << name << std::endl;
	else
		std::cout << _name << " cannot sign " << name << " because his grade is too low." << std::endl;
}

void			Bureaucrat::executeForm( AForm const & form)
{
	form.execute(*this);
}

const char	*  Bureaucrat::GradeTooHighException::what() const throw() 
{
	return   "Grade is too high.";
}

const char	*  Bureaucrat::GradeTooLowException::what() const throw() 
{
	return "Grade is too low.";
}