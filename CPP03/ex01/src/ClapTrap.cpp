/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 23:07:03 by max               #+#    #+#             */
/*   Updated: 2025/02/12 23:46:39 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() 
	: _name("ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0) 
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) 
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap constructor called" << std::endl;
	_name = name;
}

ClapTrap::ClapTrap(ClapTrap const &src) 
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = src;
}

ClapTrap & ClapTrap::operator=(ClapTrap const &other)
{
	std::cout << "ClapTrap assignation operator called" << std::endl;
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << this->_name <<  " : destructor called" << std::endl;
}

// Getters and Setters

int		ClapTrap::getHitPoints() const
{
	return this->_hitPoints;
}

int		ClapTrap::getEnergyPoints() const
{
	return this->_energyPoints;
}

int		ClapTrap::getAttackDamage() const
{
	return this->_attackDamage;
}

void	ClapTrap::setHitPoints(int hitPoints)
{
	this->_hitPoints = hitPoints;
}

void	ClapTrap::setEnergyPoints(int energyPoints)
{
	this->_energyPoints = energyPoints;
}

void	ClapTrap::setAttackDamage(int attackDamage)
{
	this->_attackDamage = attackDamage;
}

void    ClapTrap::attack(const std::string &target)
{
	if (this->_energyPoints < 0 && this->_hitPoints < 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks "
			 << target << ", causing " << this->_attackDamage 
			 << " points of damage!" << std::endl;
		this->_energyPoints -= 1;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " doesn't have enough energy points !" << std::endl;
} 


void    ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name  << " take " << amount 
				<< " points of damage!" << std::endl;
	_hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) 
{
	if (this->_energyPoints > 0) 
	{
		this->_attackDamage += amount;
		this->_energyPoints--;
		std::cout << "ClapTrap " << this->_name << " repairs itself for " << amount 
				  << " hit points!" << std::endl;
	} 
	else 
	{
		std::cout << "ClapTrap " << this->_name << " is out of energy to repair!" << std::endl;
	}
}