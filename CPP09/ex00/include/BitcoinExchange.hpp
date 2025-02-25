/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:33:12 by mgendrot          #+#    #+#             */
/*   Updated: 2025/02/25 14:15:02 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <cstdlib>
#include "Date.hpp"

#define DATA_CSV "data.csv"

class BitcoinExchange
{
	private:
		std::map<Date, float> _data_btc; 
		bool _is_false;
		
		void _open(const std::string &filename, bool is_pirt);
		void _openData(std::string line);
		void _print(std::string line);
		Date  _get_date(std::string date);
	public:
		BitcoinExchange();
		BitcoinExchange(std::string &filename);
		BitcoinExchange(const BitcoinExchange &src);
		~BitcoinExchange();
		BitcoinExchange &operator=(const BitcoinExchange &other);
		
		class OutOfRangeException : public std::exception 
		{
			public:
				virtual const char *what() const throw() 
				{
					return "Error: Value is out of range.";
				}
		};
		
		class BadInputException : public std::exception 
		{
			public:
				virtual const char *what() const throw() 
				{
					return "Error: Invalid input detected.";
				}
		};
		
		class BadFormatException : public std::exception 
		{
			public:
				virtual const char *what() const throw() { return "Error: Incorrect data format."; }
		};

};



#endif