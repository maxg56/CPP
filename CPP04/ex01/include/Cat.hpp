/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:51:21 by max               #+#    #+#             */
/*   Updated: 2025/02/13 10:39:09 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain *_brain;
    public:
        Cat();
        Cat(Cat const & src);

        Cat & operator=(Cat const & other);
        
        ~Cat();
        
        Brain* getBrain() const;

        void    makeSound() const ;
};



#endif