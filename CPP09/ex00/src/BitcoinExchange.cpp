/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxence <maxence@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:08:41 by mgendrot          #+#    #+#             */
/*   Updated: 2025/02/24 23:13:22 by maxence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(std::string filename)
{
	
	if (!this->_open_data(DATA_CSV,',',this->_data_btc) || !this->_open_data(filename,'|',this->_data_input))
		return ;
	this->_printe();
	
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
	*this = src;
}

BitcoinExchange &	BitcoinExchange::operator=(BitcoinExchange const &other) 
{
	if (this != &other) {
		this->_data_btc = other._data_btc;
		this->_data_input = other._data_input;
	}
	return *this;
}


static Date _get_date(std::string date)
{
	std::string token;
	std::istringstream stream(date);
	std::getline(stream, token, '-');
	int year = atoi(token.c_str());
	std::getline(stream, token, '-');
	int month = atoi(token.c_str());
	std::getline(stream, token, '-');
	int day = atoi(token.c_str());
	return Date(day, month, year);
}

bool    BitcoinExchange::_open_data(const std::string &filename, char sp,std::map<Date, float> &data) 
{
	try 
	{
		std::string line;
		Date Key;
		bool is_key = true;
		std::ifstream file(filename.c_str());
		if (!file.is_open()) 
            throw std::ios_base::failure(".");
		while (std::getline(file, line)) 
		{ 
			std::istringstream stream(line);
			std::string token;

			while (std::getline(stream, token, sp)) 
			{
				if (is_key) 
				{
					if (token == "date")
						continue;
					Key = _get_date(token);
					if (sp == '|')
						std::cout << "[ " << Key<<" ]" << std::endl;
					is_key = false;
				} 
				else 
				{
					data[Key] = atof(token.c_str());
					is_key = true;
				}
			}
			if (!is_key) 
			{
				data[Key]; 
				is_key = true;
			}
		}
		file.close();
	}
	catch (const std::ios_base::failure &e) 
	{
		std::cerr << "Erreur : Impossible d'ouvrir le fichier '" 
		<< filename << e.what() << std::endl;
		return false;
	}
	return true;
}



// 2011-01-03 => 3 = 0.
void	BitcoinExchange::_printe()
{
	std::map<Date, float>::iterator  it;
	for (it = this->_data_input.begin(); it != this->_data_input.end(); ++it) 
	{
		std::cout << "[ " << it->first << " =>" << it->second << " ]" << std::endl;
		if (!it->second)
			std::cout << "Error: bad input ="  << it->second << std::endl;
		else if (it->second < 0 && it->second > 1000)
		 	std::cout << "Error: not a positive number." << std::endl;
		else
		{
			float val_btc ;
			Date date = it->first;
			while (_data_btc.find(date) != this->_data_btc.end())
				date--;
			std::cout << "date = " << date << std::endl;
			std::cout << "it->second = " << it->second << std::endl;
			std::cout << "this->_data_btc[date] = " << this->_data_btc[date] << std::endl;
			val_btc = it->second * this->_data_btc[date];
			std::cout << it->first << " =>" << it->second << " = " << val_btc << "." <<  std::endl;
			
		}
		
        
    }
}

