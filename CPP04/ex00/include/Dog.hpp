/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:42:55 by max               #+#    #+#             */
/*   Updated: 2025/02/13 09:53:51 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
    private:
        
    public:
        Dog();
        Dog(Dog const & src);
        ~Dog();

        Dog & operator=(Dog const & other);

        void	makeSound() const ;
};

#endif
