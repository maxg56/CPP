/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 00:18:35 by max               #+#    #+#             */
/*   Updated: 2025/02/14 11:54:21 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() 
{
    std::cout << "=== Creating a DiamondTrap ===" << std::endl;
    DiamondTrap diamond("Diamondy");

    std::cout << "\n=== Testing DiamondTrap Actions ===" << std::endl;
    diamond.attack("Villain");
    diamond.highFivesGuys();
    diamond.whoAmI();
    std::cout << diamond.getEnergyPoints() << std::endl;
    std::cout << diamond.getHitPoints() << std::endl;
    std::cout << diamond.getAttackDamage()<< std::endl;

    std::cout << "\n=== Destroying DiamondTrap ===" << std::endl;
    return 0;
}
