/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:41:46 by mgendrot          #+#    #+#             */
/*   Updated: 2025/02/12 15:14:34 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <math.h>

Fixed::Fixed() : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(const int n) {
	std::cout << "Int constructor called" << std::endl;
	this->value = n << bits;
}

Fixed::Fixed(const float f) : value(f) {
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(f * (1 << bits));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(Fixed const &rSym) {
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &rSym)
		this->value = rSym.getRawBits();
	return *this;
}

int		Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}

void	Fixed::setRawBits(int const raw) {
	this->value = raw;
}

float	Fixed::toFloat() const 
{
	return (float)this->value / (float)(1 << bits);
}

int		Fixed::toInt() const 
{
	return this->value >> bits;
}

std::ostream&	operator<<(std::ostream& o, Fixed const &rSym) 
{
	o << rSym.toFloat();
	return o;
}

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

Fixed Fixed::operator++()
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

Fixed Fixed::operator--()
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

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return a < b ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return a > b ? a : b;
}
