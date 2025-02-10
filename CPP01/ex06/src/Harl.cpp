/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 21:58:17 by max               #+#    #+#             */
/*   Updated: 2025/02/10 23:28:15 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

void	Harl::debug() const {
	std::cout << BLUE << "[DEBUG] \n- I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << RESET << std::endl;
}

void	Harl::info() const {
	std::cout << GREEN << "[INFO] \n- I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << RESET << std::endl;
}

void	Harl::warning() const {
	std::cout << YELLOW << "[WARNING] \n- I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << RESET << std::endl;
}

void	Harl::error() const {
	std::cout << RED << "[ERROR] \n- This is unacceptable ! I want to speak to the manager now." << RESET << std::endl;
}

void Harl::complain(std::string level) 
{
    std::string arrayLevel[4] = {"debug", "info", "warning", "error"};
    int i;
    
   std::transform(level.begin(), level.end(), level.begin(), ::tolower);
    for (i = 0; i < 4; ++i) 
    {
        if (arrayLevel[i] == level)
            break;
    }
    // Gérer les cas en cascade
    switch (i) {
        case 0:
            this->debug();
            // fallthrough
        case 1:
            this->info();
            // fallthrough
        case 2:
            this->warning();
            // fallthrough
        case 3:
            this->error();
            break;
        default:
            break;
    }
}

Harl::~Harl() {}
