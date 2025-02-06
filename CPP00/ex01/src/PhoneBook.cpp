/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 08:53:28 by max               #+#    #+#             */
/*   Updated: 2025/02/06 10:45:32 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <cstdlib>



PhoneBook::PhoneBook()
{
    this->contact_index = 0;
    this->max_contact_index = 8;
}

void PhoneBook::add_contact()
{   

    std::string	name;
	std::string	last;
	std::string	nick;
	std::string	phone;
	std::string	secret;

	system("clear");
	std::cout << "Type a name : ";
	std::getline(std::cin, name);
	system("clear");
	std::cout << "Type a surname : ";
	std::getline(std::cin, last);
	system("clear");
	std::cout << "Type a nickname : ";
	std::getline(std::cin, nick);
	system("clear");
	std::cout << "Type a phone-number : ";
	std::getline(std::cin, phone);
	system("clear");
	std::cout << "Type a dark secret : ";
	std::getline(std::cin, secret);
	system("clear");
    this->contacts[this->contact_index % this->max_contact_index] = Contact(name, last, nick, phone, secret);
	this->contact_index = (this->contact_index + 1) % this->max_contact_index;

}
        
void	PhoneBook::search_contact() {
	int	i = 0;
	std::string	name;
	std::string	last;
	std::string	nick;
	std::string	phone;
	std::string	secret;
	std::string	ret;
	int	index;
	
	
	system("clear");
	if (this->contact_index == 0) {
		std::cout << "No contact avalaible ! Abort..." << std::endl; sleep(1); return;
	}
	std::cout << std::setw(5) << "Index" << "|";
	std::cout << std::setw(10) << "Firstname" << "|";
	std::cout << std::setw(10) << "Lastname" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	while (i < this->contact_index) {
		name = this->contacts[i].get_first_name();
		last = this->contacts[i].get_last_name();
		nick = this->contacts[i].get_nickname();
		phone = this->contacts[i].get_phone_number();
		secret = this->contacts[i].get_darkest_secret();
		std::cout << std::setw(5) << i << "|";
		if (name.length() > 9)
			name = name.substr(0, 9) + ".";
		if (last.length() > 9)
			last = last.substr(0, 9) + ".";
		if (nick.length() > 9)
			nick = nick.substr(0, 9) + ".";
		std::cout << std::setw(10) << name << "|";
		std::cout << std::setw(10) << last << "|";
		std::cout << std::setw(10) << nick << std::endl;
		i++;
	}
	std::cout << std::endl << "Type a contact's index to obtain personal informations : ";
	std::getline(std::cin, ret);
	index = atoi(ret.c_str());
    if ((index == 0 && ret[0] != '0') || (index > 7 || index < 0)) {
		std::cout << "Please enter a valid digit ! Abort..." << std::endl; sleep(1); return;
	}
	if (index >= this->contact_index) {
		std::cout << "No contact found ! Abort..." << std::endl; sleep(1); return;
	}
	std::cout << "Name : " << this->contacts[index].get_first_name() << std::endl;
	std::cout << "Lastname : " << this->contacts[index].get_last_name() << std::endl;
	std::cout << "Nickname : " << this->contacts[index].get_nickname() << std::endl;
	std::cout << "Phone number : " << this->contacts[index].get_phone_number() << std::endl;
	std::cout << "Darkest secret : " << this->contacts[index].get_darkest_secret() << std::endl;
	std::cout << std::endl << "Press a key to continue..." << std::endl;
	std::cin.get();
}

PhoneBook::~PhoneBook()
{
}