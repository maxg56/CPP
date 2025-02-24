/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:33:12 by mgendrot          #+#    #+#             */
/*   Updated: 2025/02/24 13:26:26 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <cstdlib>

#define DATA_CSV "data.csv"

class BitcoinExchange
{
	private:
		std::map<std::string,float> _data_btc; 
		std::map<std::string,float>_data_input;
		
		bool 	_open_data(const std::string &filename, char sp,std::map<std::string, float> &data);
		void	_printe();
		
	public:
		BitcoinExchange();
		BitcoinExchange(std::string filename);
		BitcoinExchange(BitcoinExchange const &src);
		~BitcoinExchange();
		BitcoinExchange &	operator=(BitcoinExchange const &other);
};



#endif