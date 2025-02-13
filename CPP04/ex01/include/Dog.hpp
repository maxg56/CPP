/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:42:55 by max               #+#    #+#             */
/*   Updated: 2025/02/13 10:40:49 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain *_brain;
    public:
        Dog();
        Dog(Dog const & src);
        
        Dog & operator=(Dog const & other);
        
        ~Dog();

        Brain* getBrain() const;
        
        void	makeSound() const ;
};

#endif
