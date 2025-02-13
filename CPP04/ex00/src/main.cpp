/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:10:23 by max               #+#    #+#             */
/*   Updated: 2025/02/13 10:11:48 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main() 
{
	WrongAnimal	*unknown = new WrongAnimal();
	Dog		*dog = new Dog();

	std::cout << unknown->getType() << " " << std::endl;
	std::cout << dog->getType() << " " << std::endl;

	unknown->makeSound();
	dog->makeSound();
	delete unknown;

	unknown = new WrongCat();
	unknown->makeSound();
	delete dog;
	delete unknown;
}
