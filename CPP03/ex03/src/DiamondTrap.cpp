/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 00:16:38 by max               #+#    #+#             */
/*   Updated: 2025/02/14 11:57:08 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) 
    : ClapTrap(name + "_clap_name"), FragTrap(), name(name) 
{
    this->_hitPoints = FragTrap::_hitPoints;      // 100 HP (FragTrap)
    this->_attackDamage = FragTrap::_attackDamage; 
    ScavTrap();
    this->_energyPoints = ScavTrap::_energyPoints;  // 50 EP (ScavTrap)
    
    std::cout << "DiamondTrap " << name << " has been assembled!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) 
    : ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name) {
    *this = other;
    std::cout << "DiamondTrap " << this->name << " has been copied!" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) 
{
    if (this != &other) {
        ClapTrap::operator=(other);
        this->name = other.name;
    }
    else
    {
        this->name = other.name;
    }
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << this->name << " has been dismantled!" << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
    std::cout << "I am " << this->name << " and my ClapTrap name is " << ClapTrap::_name << "!" << std::endl;
}
