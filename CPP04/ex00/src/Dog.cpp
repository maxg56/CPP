/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:44:54 by max               #+#    #+#             */
/*   Updated: 2025/02/13 10:18:20 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") 
{
	std::cout << "[C] Dog base constructor called." << std::endl;
}

Dog::Dog(const Dog& other)
	: Animal(other)
{
	std::cout << "Dog copy constructor called on " << other._type << std::endl;
}



Dog &Dog::operator=(Dog const &other) 
{
	if (this != &other) 
	{
		this->_type = other._type;
	}
	return *this;
}

Dog::~Dog() 
{
	std::cout << "[D] Dog default destructor called." << std::endl;
}

void	Dog::makeSound() const 
{
	std::cout << "[Dog] Wouf Wouf !" << std::endl;
}