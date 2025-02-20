/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:41:40 by mgendrot          #+#    #+#             */
/*   Updated: 2025/02/20 21:20:07 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string  	_target;
		
		ShrubberyCreationForm();
		
	public:
	
		// Constructors and destructors and overload
		ShrubberyCreationForm(std::string target);
		
		ShrubberyCreationForm &	operator=(ShrubberyCreationForm const &other);
		ShrubberyCreationForm(ShrubberyCreationForm const &src);
		
		~ShrubberyCreationForm();
		
		// Getters and methods
		std::string		getTarget() const;

		void	execute(Bureaucrat const & executor) const;
};

std::ostream &	operator<<(std::ostream & o, ShrubberyCreationForm const &other);

#endif
