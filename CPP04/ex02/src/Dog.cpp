/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:44:54 by max               #+#    #+#             */
/*   Updated: 2025/02/18 13:51:41 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") 
{
	this->_brain = new Brain();
	std::cout << "[C] Dog base constructor called." << std::endl;
}

Dog::Dog(const Dog& other)
	: Animal(other)
{
	this->_brain = new Brain(*other._brain);
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
	delete this->_brain;
	std::cout << "[D] Dog default destructor called." << std::endl;
}

void	Dog::makeSound() const 
{
	std::cout << "[Dog] Wouf Wouf !" << std::endl;
}

void	Dog::think() const 
{
	std::cout << "[Dog] : " + this->_brain->getIdea(this->_brain->getRandomIndex()) << std::endl;
}