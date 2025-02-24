/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxence <maxence@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:33:12 by mgendrot          #+#    #+#             */
/*   Updated: 2025/02/24 22:16:34 by maxence          ###   ########.fr       */
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
		std::map<Date,float> _data_btc; 
		std::map<Date,float>_data_input;
		
		bool 	_open_data(const std::string &filename, char sp,std::map<Date, float> &data);
		void	_printe();
		
	public:
		BitcoinExchange();
		BitcoinExchange(std::string filename);
		BitcoinExchange(BitcoinExchange const &src);
		~BitcoinExchange();
		BitcoinExchange &	operator=(BitcoinExchange const &other);
};



#endif