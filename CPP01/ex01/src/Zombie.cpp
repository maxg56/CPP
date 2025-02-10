/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ombie.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:49:04 by max               #+#    #+#             */
/*   Updated: 2025/02/10 19:52:11 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
    this->name = "default";
}

Zombie::Zombie(std::string name)
{
    this->name = name;
}

void Zombie::Announce(void)
{
    std::cout << this->name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << this->name << " is dead" << std::endl;
}