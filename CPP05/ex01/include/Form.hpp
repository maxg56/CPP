/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:23:11 by mgendrot          #+#    #+#             */
/*   Updated: 2025/02/22 14:27:20 by mgendrot         ###   ########.fr       */
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

class  Form
{
	private:
		std::string const 	_name;
		bool				_signed;
		int const			_signGrade;
		int const			_executeGrade;
		
	public:
	
	 	Form();
		Form(std::string const name, int signGrade);
		
		Form(Form const &src);
		Form & operator=(Form const & other);
		
		~Form();

		std::string		getName() const;
		bool			getSigned() const;
		int				getSignGrade() const;
		int				getExecuteGrade() const;
		
		void			beSigned(Bureaucrat &bureaucrat);

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
};
std::ostream & operator<<(std::ostream & o, Form const &other);

#endif

