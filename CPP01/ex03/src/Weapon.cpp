/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 21:00:43 by max               #+#    #+#             */
/*   Updated: 2025/02/10 21:31:13 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {}
Weapon::Weapon(std::string type) : type(type) {}

std::string& Weapon::getType(void) {
    return (this->type);
}
void Weapon::setType(std::string type) {
    this->type = type;
}

Weapon::~Weapon() {}