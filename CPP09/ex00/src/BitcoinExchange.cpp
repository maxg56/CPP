/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:08:41 by mgendrot          #+#    #+#             */
/*   Updated: 2025/02/24 18:28:37 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(std::string filename)
{
	
	if (!this->_open_data(DATA_CSV,',',this->_data_btc) || !this->_open_data(filename,'|',this->_data_input))
		return ;
	
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


bool    BitcoinExchange::_open_data(const std::string &filename, char sp,std::map<std::string, float> &data) 
{
	try 
	{
		std::string line, key;
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
					key = token;
					is_key = false;
				} 
				else 
				{
					data[key] = atof(token.c_str());
					is_key = true;
				}
			}
			if (!is_key) 
			{
				data[key] = -1; 
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



// =2011-01-03> 3 = 0.
void	BitcoinExchange::_printe()
{
	for (std::map<std::string, float>::iterator it = this->_data_input.begin(); it != this->_data_input.end(); ++it) 
	{
		if (it->second == -1)
			std::cout << "Error: bad input ="  << it->second << std::endl;
		else if (it->second < 0 && it->second > 1000)
		 	std::cout << "Error: not a positive number." << std::endl;
		else
		{
			if (it->first >= "")
			float val_btc = this->_data_btc[it->first];
			
		}
		
        std::cout << "Clé : " << it->first << " | Valeur : " << it->second << std::endl;
    }
}

