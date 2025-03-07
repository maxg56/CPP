/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 00:50:58 by max               #+#    #+#             */
/*   Updated: 2025/02/18 11:36:41 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(std::string  type) : _type(type) {
	std::cout << "[C] Animal base constructor called for type : " << this->_type << "." << std::endl;
}

Animal::Animal() : _type("UNKNOWN") {
	std::cout << "[C] Animal default constructor called." << std::endl;
}

Animal::Animal(Animal const &src) {
	*this = src;
	std::cout << "Animal copy " << src._type << std::endl;
}

Animal &	Animal::operator=(Animal const &other) 
{
	if (this != &other) {
		this->_type = other._type;
	}
	return *this;
}

Animal::~Animal() 
{
	std::cout << "[D] Default destructor called for type : " << this->_type << "." << std::endl; 
}



std::string 	Animal::getType() const 
{
	return this->_type;
}

void	Animal::makeSound() const 
{
	std::cout << "[Unknown Animal] Grrr..." << std::endl;
}

void	Animal::setType(std::string type) 
{
	this->_type = type;
}