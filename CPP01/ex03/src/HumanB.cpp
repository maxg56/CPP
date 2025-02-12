/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 21:12:38 by max               #+#    #+#             */
/*   Updated: 2025/02/12 14:41:10 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB() {}
HumanB::HumanB(std::string name) : name(name), weapon(NULL) {}


void HumanB::attack(void) 
{
    if (this->weapon == NULL)
    {
        std::cout << this->name << " has no weapon" << std::endl;
        return;
    }
    std::cout << this->name << " attacks with his " << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) 
{
    this->weapon = &weapon;
}

HumanB::~HumanB() {}
