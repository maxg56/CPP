/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 00:02:48 by max               #+#    #+#             */
/*   Updated: 2025/02/13 00:40:26 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() 
	: ClapTrap("Default")
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap has entered the battle!" << std::endl;
}
FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << name << " has entered the battle!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	*this = other;
	std::cout << "FragTrap " << this->_name << " has been copied!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " <<  this->_name << " has left the battle!" << std::endl;
}

void FragTrap::attack(const std::string& target) {
	if (this->_energyPoints > 0 && this->_hitPoints > 0) 
	{
        this->_energyPoints--;
		std::cout << "FragTrap " <<  this->_name << " launches a powerful attack on " << target 
				  << ", dealing " << this->_attackDamage << " damage!" << std::endl;
	} else {
		std::cout << "FragTrap " <<  this->_name << " has no energy or health left to attack!" << std::endl;
	}
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " <<  this->_name << " requests a high five! ✋" << std::endl;
}
