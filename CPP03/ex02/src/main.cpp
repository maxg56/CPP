/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 00:05:20 by max               #+#    #+#             */
/*   Updated: 2025/02/13 00:07:11 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() 
{
    std::cout << "\n=== Creating a FragTrap ===" << std::endl;
    FragTrap frag("Fraggy");

    std::cout << "\n=== Testing FragTrap Actions ===" << std::endl;
    frag.attack("Psycho");
    frag.highFivesGuys();

    std::cout << "\n=== Destroying Objects ===" << std::endl;
    return 0;
}

