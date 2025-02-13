/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:01:26 by max               #+#    #+#             */
/*   Updated: 2025/02/13 10:21:12 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"


WrongCat::WrongCat() : WrongAnimal("WrongCat") 
{
    std::cout << "[C] WrongCat base constructor called." << std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type) 
{
    std::cout << "[C] WrongCat base constructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
	: WrongAnimal(other)
{
	std::cout << "WrongCat copy constructor called on " << other._type << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &other) 
{
    if (this != &other) 
    {
        this->_type = other._type;
    }
    return *this;
}

WrongCat::~WrongCat() 
{
    std::cout << "[D] WrongCat default destructor called." << std::endl;
}