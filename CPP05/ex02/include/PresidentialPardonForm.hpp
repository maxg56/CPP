/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 21:03:02 by mgendrot          #+#    #+#             */
/*   Updated: 2025/02/20 21:03:29 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string  	_target;
		
		PresidentialPardonForm();
	public:
	
		// Constructors and destructors and overload
		PresidentialPardonForm(std::string target);
		
		PresidentialPardonForm &	operator=(PresidentialPardonForm const &other);
		PresidentialPardonForm(PresidentialPardonForm const &src);
		
		~PresidentialPardonForm();
		
		// Getters and methods
		std::string		getTarget() const;

		void	execute(Bureaucrat const & executor) const;
};

std::ostream &	operator<<(std::ostream & o, PresidentialPardonForm const &other);

#endif
