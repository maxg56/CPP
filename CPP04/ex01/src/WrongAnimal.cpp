/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:05:10 by max               #+#    #+#             */
/*   Updated: 2025/02/13 10:28:57 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal(std::string type) : _type(type) 
{
    std::cout << "[C] WrongAnimal base constructor called for type : " << this->_type << "." << std::endl;
}

WrongAnimal::WrongAnimal(): _type("UNKNOWN") 
{
    std::cout << "[C] WrongAnimal default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    *this = other ;
	std::cout << "WrongAnimal copy constructor called on " << other._type << std::endl;
}
WrongAnimal & WrongAnimal::operator=(WrongAnimal const &other)
{
    if (this != &other)
    {
        this->_type = other._type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal() 
{
    std::cout << "[D] WrongAnimal default destructor called for type : " << this->_type << "." << std::endl;
}

std::string WrongAnimal::getType() const 
{
    return this->_type;
}

void	WrongAnimal::makeSound() const 
{
	std::cout << "[Unknown WrongAnimal] Grrbaddibobidap..." << std::endl;
}