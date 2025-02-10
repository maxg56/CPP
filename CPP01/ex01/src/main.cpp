/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:06:59 by max               #+#    #+#             */
/*   Updated: 2025/02/10 20:34:43 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie *zombies = zombieHorde(5, "Zombie");
    
    for (int i = 0; i < 5; i++)
        zombies[i].Announce();
    delete [] zombies;
    return 0;
}
