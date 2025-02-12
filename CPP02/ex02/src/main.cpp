/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:00:31 by mgendrot          #+#    #+#             */
/*   Updated: 2025/02/12 15:07:10 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) 
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "+ operator : " << (b + d) << std::endl;
	std::cout << "- operator : " << (b - c) << std::endl;
	std::cout << "* operator : " << (b * c) << std::endl;

	if (c < b)
		std::cout << "c lower than b" << std::endl;
	else
		std::cout << "c greater than b" << std::endl;
	if (b == d)
		std::cout << "b equal d" << std::endl;
	else
		std::cout << "b different d" << std::endl;
	std::cout << a << " " << ++a << std::endl;
	std::cout << Fixed::min(b, c) << std::endl;
	std::cout << Fixed::max(b, c) << std::endl;
	return 0;
}
