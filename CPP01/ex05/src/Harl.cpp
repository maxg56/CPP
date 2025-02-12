/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 21:58:17 by max               #+#    #+#             */
/*   Updated: 2025/02/12 14:13:49 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

void	Harl::debug() const {
	std::cout << BLUE << "[DEBUG] - I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << RESET << std::endl;
}

void	Harl::info() const {
	std::cout << GREEN << "[INFO] - I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << RESET << std::endl;
}

void	Harl::warning() const {
	std::cout << YELLOW << "[WARNING] - I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << RESET << std::endl;
}

void	Harl::error() const {
	std::cout << RED << "[ERROR] - This is unacceptable ! I want to speak to the manager now." << RESET << std::endl;
}

void Harl::complain(std::string level) 
{
    void (Harl::*funcPtr)(void) const= NULL;
    void (Harl::*harl_f[])(void) const= {
         &Harl::debug,
         &Harl::info,
         &Harl::warning,
         &Harl::error
    };
    std::string	arrayLevel[4] = 
    {"debug", "info", "warning", "error"};
    for (int i = 0; i < 4; i++)
    {
        if (arrayLevel[i] == level)
        {
            funcPtr = harl_f[i];
            break;
        }
    }
	if (!funcPtr) {
		std::cout << "Invalid Harl's complain !" << std::endl; return;
	}
	(this->*funcPtr)();
}

Harl::~Harl() {}