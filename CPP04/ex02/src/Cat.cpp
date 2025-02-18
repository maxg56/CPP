/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:54:14 by max               #+#    #+#             */
/*   Updated: 2025/02/18 14:23:48 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") 
{
    std::cout << "[C] Cat base constructor called." << std::endl;
    this->_brain = new Brain();
}

Cat::Cat(const Cat& other)
	: Animal(other)
{
	std::cout << "Cat copy constructor called on " << other._type << std::endl;
    this->_brain = new Brain(*other._brain);
}

Cat &Cat::operator=(Cat const &other) 
{
    if (this != &other) 
    {
        this->_type = other._type;
        delete this->_brain;
    }
    return *this;
}

Cat::~Cat() 
{
    delete this->_brain;
    std::cout << "[D] Cat default destructor called." << std::endl;
}

void	Cat::makeSound() const 
{
    std::cout << "[Cat] Miaou Miaou !" << std::endl;
}

void	Cat::think() const
{
    if (this->_brain) {
        int index = this->_brain->getRandomIndex();
        std::cout << "[Cat] : " << this->_brain->getIdea(index) << std::endl;
    } else {
        std::cout << "[Cat] : I have no brain... (Error)" << std::endl;
    }
}
