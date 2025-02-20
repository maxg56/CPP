/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:23:11 by mgendrot          #+#    #+#             */
/*   Updated: 2025/02/20 21:36:09 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>

#include "Bureaucrat.hpp"

#define COLOR_RESET "\033[0m"
#define COLOR_RED "\033[31m"
#define COLOR_GREEN "\033[32m"
#define COLOR_BLUE "\033[34m"
#define COLOR_CYAN "\033[36m"

class Bureaucrat;

class  AForm
{
	protected:
		std::string const 	_name;
		bool				_signed;
		int const			_signGrade;
		int const			_executeGrade;
		
	public:

		// Constructors and destructors and overload
	 	AForm();
		AForm(std::string const name, int signGrade, int executeGrade);
		
		AForm(AForm const &src);
		AForm & operator=(AForm const & other);
		
		virtual ~AForm();

		// Getters
		std::string		getName() const;
		bool			getSigned() const;
		int				getSignGrade() const;
		int				getExecuteGrade() const;
		
		// Methods
		void			beSigned(Bureaucrat &bureaucrat);
	 	virtual void	execute(Bureaucrat const & executor) const = 0;

		// Exceptions
		class GradeTooHighException : public std::exception 
		{
			public:
				virtual const char *	what() const throw();
		};
		class GradeTooLowException : public std::exception 
		{
			public:
				virtual const char *	what() const throw();
		};
		class  FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class  FormSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream & operator<<(std::ostream & o, AForm const &other);

#endif