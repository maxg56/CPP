/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:44:41 by mgendrot          #+#    #+#             */
/*   Updated: 2025/02/25 15:04:52 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>

class RPN
{
private:
	std::stack<double> numbers;
public:
	RPN();
	RPN(std::stack<double> number);
	RPN(const RPN &var);
	~RPN();
	RPN &operator=(const RPN &var);
	void calculate(std::string input);
	class InputException : public std::exception 
	{
		public:
			virtual const char *what() const throw() {return "Error: Invalid input";}
	};
	class Div0Exception : public std::exception 
	{
		public:
			virtual const char *what() const throw() {return "Error: Division by zero";}
	};
	
};