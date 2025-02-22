/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:34:33 by mgendrot          #+#    #+#             */
/*   Updated: 2025/02/22 15:37:17 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <iostream>
#include <string>

typedef std::string str;

template<typename T>
void	swap(T &a, T &b);

template<typename T>
T	min(T a, T b);

template<typename T>
T	max(T a, T b);

#endif