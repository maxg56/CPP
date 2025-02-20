/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:43:00 by max               #+#    #+#             */
/*   Updated: 2025/02/20 15:11:07 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

#include <iostream>

Brain::Brain()
{
	const std::string examples[] = {
		"I want to sleep",
		"I want food",
		"I want pets",
		"I want to go for a walk",
		"I want water",
		"I want a treat",
		"I want to play",
		"I want to go outside",
		"I want to go inside",
		"I want to go to the park",
		"I want to go to the beach",
		"I want to go to the forest",
		"I want to go to the mountains",
		"I want to go to the lake",
		"I want to go to the river",
		"I want to go to the sea",
		"I want to go to the ocean",
		"I want to go to the desert",
		"I want to go to the jungle",
		"I want to go to the savannah",
		"I want to go to the tundra",
		"I want to go to the arctic",
		"I want to go to the antarctic",
		"I want to go to the moon",
		"I want to go to the mars",
		"I want to go to the venus",
		"I want to go to the jupiter",
		"I want to go to the saturn"
	};
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = examples[rand() % (sizeof(examples) / sizeof(std::string))];
	std::cout << "[C] Brain(void) constructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = other._ideas[i];
	std::cout << "[CO] Brain copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = rhs._ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "[D] Brain destructor called" << std::endl;
}

const std::string& Brain::getIdea(int index) const
{
	return this->_ideas[index];
}

int Brain::getRandomIndex() const
{
	return rand() % 100;
}