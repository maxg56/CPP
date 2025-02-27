/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:08:41 by mgendrot          #+#    #+#             */
/*   Updated: 2025/02/27 02:27:47 by mgendrot         ###   ########.fr       */
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
    std::size_t i_d = 0, i_f = 0;
    int d[] = {-1,-1,-1}, i;
    for (i = 0; i < 3; i++) 
    {
        i_f = date.find('-', i_d);
        if (i_f == std::string::npos)
            i_f = date.size() -1;
        d[i] = std::strtol(date.substr(i_d, (i_f - i_d) ).c_str(), NULL, 10);
        i_d = i_f + 1;
    }
    return Date(d[2], d[1], d[0]); 
}

void BitcoinExchange::_openData(std::string line)
{
	size_t i_m;

	try
	{
		i_m = line.find(',');
		if (i_m == std::string::npos)
			throw BadFormatException();
		this->_data_btc[_get_date(line.substr(0, i_m).c_str())] = 
				atof(line.substr(i_m + 1, line.size() - (i_m + 1)).c_str());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << " (" << line << ")" << std::endl;
	}
}

void  BitcoinExchange::_print(std::string line)
{
	try
	{
		size_t i_m;
		float nb_btc = 0.0f, val_btc = 0.0f;
		Date Key , date;

		i_m = line.find('|');
		if (i_m == std::string::npos)
			throw BadFormatException();
		Key = Date(_get_date(line.substr(0, i_m).c_str()));
		if (!Key.check_date())
			throw BadInputException();
		date = Key;
		std::map<Date, float>::iterator it = this->_data_btc.find(Key);
		if (it == this->_data_btc.end()) 
		{
			it = this->_data_btc.begin();
			while (it != this->_data_btc.end() && it->first <= Key)
				++it;
			if (it == this->_data_btc.begin()) 
				throw std::runtime_error("Error: No valid exchange rate found for date ");
			--it;
		}
		Key = it->first;
		nb_btc = atof(line.substr(i_m + 1, line.size() - ( i_m + 1)).c_str());
		if (nb_btc < 0 || nb_btc > 1000)
			throw OutOfRangeException();
		val_btc = nb_btc == 1 ?  this->_data_btc[Key] :nb_btc * this->_data_btc[Key];
		std::cout << date << " => " << nb_btc << " = " << val_btc << std::endl;
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
		std::getline(file, line);
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






