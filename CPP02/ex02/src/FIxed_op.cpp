/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FIxed_op.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:12:17 by mgendrot          #+#    #+#             */
/*   Updated: 2025/02/12 12:58:19 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

bool	Fixed::operator>(const Fixed& other) const {
	return this->value > other.getRawBits();
}

bool	Fixed::operator<(const Fixed& other) const {
	return this->value < other.getRawBits();
}

bool Fixed::operator>=(const Fixed& other) const
{
	return this->value >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed& other) const
{
	return this->value<= other.getRawBits();
}

bool Fixed::operator==(const Fixed& other) const
{
	return this->value == other.getRawBits();
}

bool Fixed::operator!=(const Fixed& other) const 
{
	return this->value != other.getRawBits();
}


Fixed Fixed::operator+(const Fixed& other) const 
{
    return Fixed(this->value + other.value);
}

Fixed Fixed::operator-(const Fixed& other) const 
{
    return Fixed(this->value - other.value);
}

Fixed Fixed::operator*(const Fixed& other) const 
{
    return Fixed(this->value * other.value);
}

Fixed Fixed::operator/(const Fixed& other) const 
{
    if (other.value == 0) {
        throw std::runtime_error("Division par zéro");
    }
    return Fixed(this->value / other.value);
}

Fixed& Fixed::operator++()
{
    this->value += 0.0001;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    value += 0.0001;
    return temp;
}

Fixed& Fixed::operator--()
{
    this->value -= 0.0001;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    value -= 0.0001;
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return a < b ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return a > b ? a : b;
}
