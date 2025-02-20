/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:03:55 by mgendrot          #+#    #+#             */
/*   Updated: 2025/02/20 18:27:07 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() :_name("UNKNOWN") ,_signed(false), _signGrade(0), _executeGrade(0) 
{
	std::cout << "[C] Form default constructor called." << std::endl;
}

Form::Form(std::string const name, int signGrade) 
	: 	_name(name), _signed(false), _signGrade(signGrade), _executeGrade(0)
{
	std::cout << "[C] Form constructor called." << std::endl;
	if (_signGrade < 1)
		throw Form::GradeTooHighException();
	if (_signGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const &src) 
	: _name(src.getName()), _signed(src.getSigned()),
	 _signGrade(src.getSignGrade()), _executeGrade(src.getExecuteGrade()) 
{
	std::cout << "[C] Form copy constructor called." << std::endl;
	*this = src;
}

Form &	Form::operator=(Form const &other) 
{
	if (this != &other) {
		this->_signed = other._signed;
	}
	return *this;
}

Form::~Form() 
{
	std::cout << "[D] Form default destructor called." << std::endl;
}

std::ostream &	operator<<(std::ostream & o, Form const &other) 
{
	o << other.getName() << ", form signed : " << (other.getSigned() ? "true" : "false");
	return o;
}

std::string		Form::getName() const { return this->_name; }
bool			Form::getSigned() const { return _signed; }
int				Form::getSignGrade() const { return _signGrade; }
int				Form::getExecuteGrade() const { return _executeGrade; }

void			Form::beSigned(Bureaucrat &bureaucrat)
{
	if (this->_signed)
	{
		std::cout << "The form is already signed." << std::endl;
		return ;
	}
	if (bureaucrat.getGrade() > this->_signGrade)
	{
		bureaucrat.signForm(this->_name, false);
		throw Form::GradeTooLowException();
	}
	this->_signed = true;
	bureaucrat.signForm(this->_name, true);
}

const char *	Form::GradeTooHighException::what() const throw() 
{
	return ("The bureaucrat is too senior to do this.");
}

const char *	Form::GradeTooLowException::what() const throw() 
{
	return ("The bureaucrat don't have the ability to do this.");
}
