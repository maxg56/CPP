/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:25:31 by babreton          #+#    #+#             */
/*   Updated: 2025/02/24 14:18:32 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template<typename T>
void	iter(T *adress, int lenght, void (*fct)(T& var))
{
	for (int i = 0; i < lenght; i++)
		fct(adress[i]);
}

template<typename T>
void	iter(const T *adress, int lenght, void (*fct)(const T& var))
{
	for (int i = 0; i < lenght; i++)
		fct(adress[i]);
}

template<typename T>
void	printValue(T& val)
{
	std::cout << val;
}


#endif