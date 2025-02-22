/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:07:24 by mgendrot          #+#    #+#             */
/*   Updated: 2025/02/22 17:36:17 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef _EASYFIND_HPP_
#define _EASYFIND_HPP_

#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <exception>
#include <vector>
#define _4  10000

class NoValueException : public std::exception 
{
	public:
		virtual const char *	what() const throw();
};

template<typename T>
int	easyfind(T const & array, int val)
{
	typename T::const_iterator it = std::find(array.begin(), array.end(), val);
	if (it == array.end())
	{
		throw NoValueException();
	}
	return *it;
};

const char *	NoValueException::what() const throw()
{
	return "No value in array";
}

#endif