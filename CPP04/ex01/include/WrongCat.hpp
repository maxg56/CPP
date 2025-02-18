/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:57:57 by max               #+#    #+#             */
/*   Updated: 2025/02/13 10:03:25 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat 
    : public WrongAnimal 
{
    
	public:
		WrongCat();
        WrongCat(std::string type);
		WrongCat(WrongCat const &src);
		~WrongCat();

		WrongCat &	operator=(WrongCat const &rSym);

		void	makeSound() const;
};

#endif

