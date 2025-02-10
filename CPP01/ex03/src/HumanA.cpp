/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 21:04:16 by max               #+#    #+#             */
/*   Updated: 2025/02/10 21:32:00 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA() {}

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(&weapon) {}

void HumanA::attack(void) 
{
    std::cout << this->name << " attacks with his " << this->weapon->getType() << std::endl;
}

HumanA::~HumanA() {}
