/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 08:56:50 by max               #+#    #+#             */
/*   Updated: 2025/02/21 12:16:40 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACE_HPP
# define CONTACE_HPP

#include <iostream>
#include <cctype>
#include <cstdio>


#include <string>

class Contact {
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
    
    public:
        Contact();
        Contact(std::string first_name, std::string last_name, \
                std::string nickname,std::string phone_number, \
                std::string darkest_secret);
        std::string get_first_name();
        std::string get_last_name();
        std::string get_nickname();
        std::string get_phone_number();
        std::string get_darkest_secret();
        ~Contact();
};

#endif