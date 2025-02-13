/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 00:47:30 by max               #+#    #+#             */
/*   Updated: 2025/02/13 10:24:44 by max              ###   ########.fr       */
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

        Animal & operator=(Animal const & other);
        std::string getType() const;
        
        virtual void makeSound() const ;
};

#endif