/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:54:14 by max               #+#    #+#             */
/*   Updated: 2025/02/13 10:19:01 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") 
{
    std::cout << "[C] Cat base constructor called." << std::endl;
}

Cat::Cat(const Cat& other)
	: Animal(other)
{
	std::cout << "Cat copy constructor called on " << other._type << std::endl;
}

Cat &Cat::operator=(Cat const &other) 
{
    if (this != &other) 
    {
        this->_type = other._type;
    }
    return *this;
}

Cat::~Cat() 
{
    std::cout << "[D] Cat default destructor called." << std::endl;
}

void	Cat::makeSound() const 
{
    std::cout << "[Cat] Miaou Miaou !" << std::endl;
}