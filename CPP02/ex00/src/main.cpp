/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:45:27 by mgendrot          #+#    #+#             */
/*   Updated: 2025/02/11 13:08:00 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main() {
    Fixed a;
    Fixed b(a);
    Fixed c;
    c = a;
	
    std::cout << "a.getRawBits(): " << a.getRawBits() << std::endl;
    std::cout << "b.getRawBits(): " << b.getRawBits() << std::endl;
    std::cout << "c.getRawBits(): " << c.getRawBits() << std::endl;

    return 0;
}


