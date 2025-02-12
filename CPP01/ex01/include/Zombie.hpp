/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:46:02 by max               #+#    #+#             */
/*   Updated: 2025/02/12 14:06:48 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>


class Zombie
{
    private:
         std::string name;
    public:
        Zombie();
        Zombie(std::string name);
        void setZombie(std::string name);
        void Announce(void);
        ~Zombie();
};

Zombie* zombieHorde( int N, std::string name );

#endif
