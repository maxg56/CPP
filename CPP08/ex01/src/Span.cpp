/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:49:28 by mgendrot          #+#    #+#             */
/*   Updated: 2025/02/22 17:58:12 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _maxSize(0), _size(0) {}

Span::Span(unsigned int N) : _maxSize(N), _size(0) {}

Span::Span(Span const &src) 
{
	this->_array = src._array;
	this->_maxSize = src._maxSize;
	this->_size = src._size;
}

Span::~Span() {
}

Span &	Span::operator=(Span const &other) 
{
	if (this != &other) 
	{
		this->_array = other._array;
		this->_maxSize = other._maxSize;
		this->_size = other._size;
	}
	return *this;
}

void				Span::addNumber(int n) 
{
	if (this->_size == this->_maxSize)
		throw Span::MaxNumbersException();
	this->_array.push_back(n);
	this->_size++;
}

void				Span::bigAdd(int n) {
	if (this->_size + n > this->_maxSize) 
	{
		std::cout << "Can't add " << n << " elements to the array, the max_size will be reached." << std::endl; return;
	}
	
	int nb = 0;
	for (int i = 0; i < n; i++) 
	{
		nb = rand() % 100 + 1;
		this->addNumber(nb);
		std::cout << this->_size << " / " << this->_maxSize << " : " << nb << std::endl;
	}
}

int Span::shortestSpan()
{
	if (!this->_array.size())
		throw Span::NoNumberException();
	if (this->_array.size() == 1)
		throw Span::OneNumberException();
	std::vector<int> tmp(this->_array);
	std::sort(tmp.begin(), tmp.end());
	int min = tmp[1] - tmp[0];
	for (size_t i = 2; i < tmp.size(); i++) {
		if (tmp[i] - tmp[i - 1] < min)
			min = tmp[i] - tmp[i - 1];
	}
	return min;
}


int		Span::longestSpan() const 
{
	if (!this->_array.size())
		throw Span::NoNumberException();
	if (this->_array.size() == 1)
		throw Span::OneNumberException();
		
	int	max = *std::max_element(this->_array.begin(), this->_array.end());
	int	min = *std::min_element(this->_array.begin(), this->_array.end());

	return max - min;
}

const char *		Span::MaxNumbersException::what() const throw() {
	return "Can't add a new number to the array: max size reached";
}

const char *	Span::NoNumberException::what() const throw() {
	return "The requested range cannot be found: array is empty.";
}

const char *	Span::OneNumberException::what() const throw() {
	return "The requested range cannot be found: array contain only one number.";
}