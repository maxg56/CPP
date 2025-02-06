/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 08:50:57 by max               #+#    #+#             */
/*   Updated: 2025/02/06 10:25:28 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contace.hpp"


class PhoneBook
{
    private:
        int contact_index;
        int max_contact_index;
        Contact contacts[8];
    public:
        PhoneBook();
        void add_contact();
        void search_contact();
        
        ~PhoneBook();
};
    
#endif
