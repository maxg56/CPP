/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 00:47:30 by max               #+#    #+#             */
/*   Updated: 2025/02/18 14:27:29 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANINMAL_HPP
# define ANINMAL_HPP

#include <iostream>

class Animal
{
    protected:
        std::string _type;
    
    public:
        Animal(std::string type);
        Animal();
        Animal(Animal const & src);
        virtual ~Animal();

        Animal &        operator=(Animal const & other);
        std::string     getType() const;
        void            setType(std::string type);
        
        virtual void    makeSound() const = 0;
        virtual void    think() const = 0;
};

#endif