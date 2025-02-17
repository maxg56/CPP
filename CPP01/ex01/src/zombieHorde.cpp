/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:07:52 by max               #+#    #+#             */
/*   Updated: 2025/02/12 14:33:33 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *zombies = new Zombie[N];
	
	for (int i = 0; i < N; i++)
	{
		zombies[i].setZombie(name);
	}
	
	return zombies;
}