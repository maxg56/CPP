/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 23:29:35 by max               #+#    #+#             */
/*   Updated: 2025/02/12 23:48:00 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() 
{
    ClapTrap clapTrap("BOBE");
    ClapTrap clapTrap2(clapTrap);
    
    clapTrap.attack("enemy");
    clapTrap.takeDamage(5);
    clapTrap.beRepaired(5);
    clapTrap2.attack("enemy");

    return 0;
}