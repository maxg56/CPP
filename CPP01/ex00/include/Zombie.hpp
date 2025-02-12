/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:46:02 by max               #+#    #+#             */
/*   Updated: 2025/02/12 14:04:34 by mgendrot         ###   ########.fr       */
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
        void Announce(void);
        ~Zombie();
};

void    randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif
