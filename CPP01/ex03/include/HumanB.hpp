/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 21:11:32 by max               #+#    #+#             */
/*   Updated: 2025/02/12 14:39:12 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	private:
		std::string name;
		Weapon		*weapon;
	public:
		HumanB();
		HumanB(std::string name);
		void attack(void);
		void setWeapon(Weapon &weapon);
		~HumanB();
};

#endif