/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:35:17 by max               #+#    #+#             */
/*   Updated: 2025/02/18 13:52:40 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class Brain
{
	private:
		std::string _ideas[100];
		
	public:
	
		Brain();
		Brain(const Brain& other);
	
		Brain& operator=(const Brain& rhs);

		~Brain();

		const std::string& getIdea(int index) const;
		int getRandomIndex() const;


};

#endif