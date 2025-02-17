/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:35:06 by mgendrot          #+#    #+#             */
/*   Updated: 2025/02/11 13:51:40 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int                 value;
		static const int    bits= 8;

	public:
		Fixed();
		explicit Fixed(int const value);
		explicit Fixed(float const value);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		friend std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
		float toFloat(void) const; 
		int toInt(void) const;
		int getRawBits(void) const;
		void setRawBits(int const raw);
		~Fixed();
};


#endif