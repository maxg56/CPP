/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:08:08 by mgendrot          #+#    #+#             */
/*   Updated: 2025/02/24 13:05:43 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <climits>
#include "Form.hpp"

class Bureaucrat
{
	private:
		std::string const 	_name;
		int					_grade;
		 
	public:
		Bureaucrat();
		Bureaucrat(std::string const name, int grade);
		
		Bureaucrat(Bureaucrat const &src);
		Bureaucrat & operator=(Bureaucrat const & other);
		
		~Bureaucrat();
		std::string		getName() const;
		int				getGrade() const;

		void			promote();
		void			demote();

		void			signForm(std::string name, bool sign);
		

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
std::ostream &	operator<<(std::ostream & o, Bureaucrat const &other) ;

#endif