/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:51:21 by max               #+#    #+#             */
/*   Updated: 2025/02/13 09:53:41 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
    private:
        
    public:
        Cat();
        Cat(Cat const & src);
        ~Cat();

        Cat & operator=(Cat const & other);

        void    makeSound() const ;
};



#endif