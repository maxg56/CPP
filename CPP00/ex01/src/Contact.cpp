/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 09:04:26 by max               #+#    #+#             */
/*   Updated: 2025/02/06 10:06:44 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contace.hpp"

Contact::Contact(std::string first_name, std::string last_name, std::string nickname,
                 std::string phone_number, std::string darkest_secret)
{
    Contact::first_name = first_name;
    Contact::last_name = last_name;
    Contact::nickname = nickname;
    Contact::phone_number = phone_number;
    Contact::darkest_secret = darkest_secret;
}


std::string Contact::get_first_name()
{
    return (Contact::first_name);
}

std::string Contact::get_last_name()
{
    return (Contact::last_name);
}

std::string Contact::get_nickname()
{
    return (Contact::nickname);
}

std::string Contact::get_phone_number()
{
    return (Contact::phone_number);
}

std::string Contact::get_darkest_secret()
{
    return (Contact::darkest_secret);
}

Contact::~Contact() 
{
    
}
