/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:52:31 by max               #+#    #+#             */
/*   Updated: 2025/02/12 14:04:20 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{   
    Zombie *zombie = newZombie("Zombie1");
    delete zombie;
    randomChump("Zombie2");
    return 0;
}