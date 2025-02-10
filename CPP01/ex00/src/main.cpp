/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:52:31 by max               #+#    #+#             */
/*   Updated: 2025/02/10 20:02:11 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
    Zombie *zombie = new Zombie(name);
    zombie->Announce();
    return zombie;
}

void randomChump(std::string name)
{
    Zombie zombie(name);
    zombie.Announce();
}

int main(void)
{   
    Zombie *zombie = newZombie("Zombie1");
    delete zombie;
    randomChump("Zombie2");
    return 0;
}