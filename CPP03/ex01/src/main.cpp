/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 23:56:30 by max               #+#    #+#             */
/*   Updated: 2025/02/12 23:56:46 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
    std::cout << "=== Creating a ScavTrap ===" << std::endl;
    ScavTrap scav("Scavy");

    std::cout << "\n=== Testing ScavTrap Actions ===" << std::endl;
    scav.attack("Bandit");
    scav.guardGate();

    std::cout << "\n=== Destroying ScavTrap ===" << std::endl;
    return 0;
}
