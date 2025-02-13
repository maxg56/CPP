/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:35:17 by max               #+#    #+#             */
/*   Updated: 2025/02/13 10:46:33 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	private:
		std::string _ideas[100];
		std::string	ideaGenerator() const;
	public:
	
		Brain();
		Brain(const Brain& other);
	
		Brain& operator=(const Brain& rhs);

		~Brain();

		const std::string& getIdea(int index) const;


};

#endif