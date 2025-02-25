/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:08:41 by mgendrot          #+#    #+#             */
/*   Updated: 2025/02/25 14:10:56 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(std::string &filename)
{
	
	this->_is_false = true;
	this->_open(DATA_CSV, false);
	if (!this->_is_false)
		return;
 	this->_open(filename, true);
	if (!this->_is_false)
		return;
}


BitcoinExchange::BitcoinExchange(BitcoinExchange const &src){ *this = src;}
BitcoinExchange &	BitcoinExchange::operator=(BitcoinExchange const &other) 
{
	if (this != &other) {
		this->_data_btc = other._data_btc;
	}
	return *this;
}

Date BitcoinExchange::_get_date(std::string date)
{
    std::string token;
    std::istringstream stream(date);
    int year = 0, month = 0, day = 0;

    std::getline(stream, token, '-');
    try {
        year = std::atoi(token.c_str());
    } catch (const std::invalid_argument& e) {
        throw BadInputException();
    }
    std::getline(stream, token, '-');
    try {
        month = std::atoi(token.c_str());
    } catch (const std::invalid_argument& e) {
        throw BadInputException();
    }
    std::getline(stream, token, '-');
    try {
        day = atoi(token.c_str());
    } catch (const std::invalid_argument& e) {
        throw BadInputException();
    }
    return Date(day, month, year);
}


void BitcoinExchange::_openData(std::string line)
{
	std::istringstream stream(line);
	std::string token;
	Date Key;
	bool is_key = true;
	
	while (std::getline(stream, token, ',')) 
	{
		if (is_key) 
		{
			if (token == "date ")
				break ;
			Key = _get_date(token);
			is_key = false;
		} 
		else 
		{
			this->_data_btc[Key] = atof(token.c_str());
			is_key = true;
		}
	}
	if (!is_key) 
	{
		this->_data_btc[Key] = -42;
		is_key = true;
	}
}

void  BitcoinExchange::_print(std::string line)
{
	try
	{
		if (line == "date | value") 
			return ;
		std::istringstream stream(line);
		std::string token;
		bool is_key = true;
		float nb_btc = 0.0f, val_btc = 0.0f;
		Date Key , date;

		while (std::getline(stream, token, '|')) 
		{
			if (is_key) 
			{
				Key = Date(_get_date(token));
				if (!Key.is_valide)
					throw BadInputException();
				date = Key;
				// Recherche manuelle de la date disponible la plus proche
				std::map<Date, float>::iterator it = this->_data_btc.find(Key);
				if (it == this->_data_btc.end()) 
				{
					it = this->_data_btc.begin();
					while (it != this->_data_btc.end() && it->first <= Key)
						++it;
					if (it == this->_data_btc.begin()) 
						throw std::runtime_error("Error: No valid exchange rate found for date " + token);
					--it;
				}
				Key = it->first;
				is_key = false;
			} 
			else 
			{
				std::stringstream ss(token);
				if (!(ss >> nb_btc) || !ss.eof())
					throw BadFormatException();
				if (nb_btc < 0 || nb_btc > 1000)
					throw OutOfRangeException();
				val_btc = nb_btc == 1 ?  this->_data_btc[Key] :nb_btc * this->_data_btc[Key];
				std::cout << date << " => " << nb_btc << " = " << val_btc << std::endl;
				is_key = true;
			}
		}
		if (!is_key) 
			throw BadFormatException();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << " (" << line << ")" << std::endl;
	}
}

void   BitcoinExchange::_open(
	const std::string &filename,bool is_pirt)
{
	try 
	{
		std::string line;
		std::ifstream file(filename.c_str());
		if (!file.is_open()) 
			throw std::ios_base::failure(".");
		while (std::getline(file, line)) 
		{ 
			if (is_pirt)
				this->_print(line);
			else
				this->_openData(line);
		}
		file.close();
	}
	catch (const std::ios_base::failure &e) 
	{
		this->_is_false = false;
		std::cerr << "Erreur : Impossible d'ouvrir le fichier '" 
		<< filename << e.what() << std::endl;
	}
}






