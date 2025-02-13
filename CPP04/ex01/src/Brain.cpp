/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:43:00 by max               #+#    #+#             */
/*   Updated: 2025/02/13 10:48:39 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "[C] Neuronal creation of brain. Loading..." << std::endl;
	int	i = -1;
	while (++i < 100)
		this->_ideas[i] = this->ideaGenerator();
	std::cout << std::endl;
}

Brain::Brain(Brain const &src) {
	*this = src;
}

Brain &	Brain::operator=(Brain const &rSym) {
	if (this != &rSym) {
		int	i = -1;
		while (++i < 100)
			this->_ideas[i] = rSym._ideas[i];
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "[D] Brain destruction, no turning back. Loading..." << std::endl;
}

std::string Brain::ideaGenerator() const {
	srand((unsigned)time(NULL) * getpid());
	
	std::string tmp;
	int min = 4;
	int max = 12;
	int random = min + rand() % (max - min + 1);
	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";

	tmp.reserve(random);
	int i = 0;
	for (int i = 0; i < random; ++i) {
        tmp += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
	return tmp;
}

std::string	Brain::getRandomIdea() const {
	int	min = 0;
	int	max = 99;
	int random = min + rand() % (max - min + 1);

	return this->_ideas[random];
}