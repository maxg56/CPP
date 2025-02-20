/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:55:37 by mgendrot          #+#    #+#             */
/*   Updated: 2025/02/20 20:57:59 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"


class RobotomyRequestForm : public AForm
{
	private:
		std::string  	_target;
		
		RobotomyRequestForm();
	public:
	
		// Constructors and destructors and overload
		RobotomyRequestForm(std::string target);
		
		RobotomyRequestForm &	operator=(RobotomyRequestForm const &other);
		RobotomyRequestForm(RobotomyRequestForm const &src);
		
		~RobotomyRequestForm();
		
		// Getters and methods
		std::string		getTarget() const;

		void	execute(Bureaucrat const & executor) const;
};

std::ostream &	operator<<(std::ostream & o, RobotomyRequestForm const &other);

#endif