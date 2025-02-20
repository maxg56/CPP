/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:03:55 by mgendrot          #+#    #+#             */
/*   Updated: 2025/02/20 21:16:50 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() :_name("UNKNOWN") ,_signed(false), _signGrade(0), _executeGrade(0) 
{
	std::cout << "[C] Form default constructor called." << std::endl;
}

AForm::AForm(std::string const name, int signGrade, int executeGrade) 
	: 	_name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	std::cout << "[C] Form constructor called." << std::endl;
	if (_signGrade < 1)
		throw AForm::GradeTooHighException();
	if (_signGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const &src) 
	: _name(src.getName()), _signed(src.getSigned()),
	 _signGrade(src.getSignGrade()), _executeGrade(src.getExecuteGrade()) 
{
	std::cout << "[C] Form copy constructor called." << std::endl;
	*this = src;
}

AForm &	AForm::operator=(AForm const &other) 
{
	if (this != &other) {
		this->_signed = other._signed;
	}
	return *this;
}

AForm::~AForm() 
{
	std::cout << "[D] Form default destructor called." << std::endl;
}

std::ostream &	operator<<(std::ostream & o, AForm const &other) 
{
	o << other.getName() << ", form signed : " << 
	(other.getSigned() ? "true" : "false");
	return o;
}

std::string		AForm::getName() const { return _name; }
bool			AForm::getSigned() const { return _signed; }
int				AForm::getSignGrade() const { return _signGrade; }
int				AForm::getExecuteGrade() const { return _executeGrade; }

void			AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (this->_signed)
		throw(AForm::FormSignedException());
	if (bureaucrat.getGrade() > this->_signGrade)
	{
		bureaucrat.signForm(this->_name, false);
		throw AForm::GradeTooLowException();
	}
	this->_signed = true;
	bureaucrat.signForm(this->_name, true);
}


const char *	AForm::GradeTooHighException::what() const throw() 
{
	return ("The bureaucrat is too senior to do this.");
}

const char *	AForm::GradeTooLowException::what() const throw() 
{
	return ("The bureaucrat don't have the ability to do this.");
}

const char *  AForm::FormNotSignedException::what() const throw() 
{
	return ("The form is not signed.");
}

const char *  AForm::FormSignedException::what() const throw() 
{
	return ("The form is already signed.");
}