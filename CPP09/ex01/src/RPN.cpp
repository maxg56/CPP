/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:23:57 by mgendrot          #+#    #+#             */
/*   Updated: 2025/02/25 16:50:59 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include "RPN.hpp"

RPN::RPN(){}
RPN::~RPN(){}
RPN::RPN(std::stack<double> number){this->numbers = number;}
RPN::RPN(const RPN &var){*this = var;}
RPN &RPN::operator=(const RPN &var){this->numbers = var.numbers;return (*this);}

void RPN::calculate(std::string input)
{
	try
	{
		static std::string sin = "+-*/";
		for (size_t i = 0; i < input.size(); i++)
		{
			char c = input[i];
	
			if (c == ' ')
				continue;
			else if (isdigit(c))
			{
				int number = c - '0';
				numbers.push(number);
			}
			else if (numbers.size() >= 2)
			{
				int i = 0;
				double b = numbers.top();
				numbers.pop();
				double a = numbers.top();
				numbers.pop();
				while ( i < 4)
				{
					if (c == sin[i])
						break;
					i++;
				}
				switch (i)
				{
					case 0:
						numbers.push(a + b);
						break;
					case 1:
						numbers.push(a - b);
						break ;
					case 2:
						numbers.push(a * b);
						break;
					case 3:
						if (b == 0)
							throw Div0Exception();
						numbers.push(a / b);
						break;
				default:
					throw InputException();
					break;
				}
			}
			else
				throw InputException();
		}
		if (numbers.size() == 1)
		{
			double result = numbers.top();
			numbers.pop();
			std::cout << "Result: " << result << std::endl;
		}
		else
			throw InputException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

	
