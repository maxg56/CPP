/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 22:11:06 by maxence           #+#    #+#             */
/*   Updated: 2025/02/27 02:27:16 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATE_HPP
#define DATE_HPP

#include <iostream>

class Date
{
    private:
        int _day;
        int _month;
        int _year;
        
        void _maintenant();
        bool _bissextile() const;
        int  _longueur_mois(int month) const;

    public:
        bool is_valide;
        Date();
        Date(int day, int month, int year);
        Date(Date const &src);
        ~Date();

        Date &operator=(Date const &other);

        // Incrémentation et décrémentation
        Date &operator++();   // Préfixe (++d)
        Date operator++(int); // Suffixe (d++)
        Date &operator--();   // Préfixe (--d)
        Date operator--(int); // Suffixe (d--)

     
        // Comparaisons
        bool operator==(Date const &rhs) const;
        bool operator!=(Date const &rhs) const;
        bool operator>(Date const &rhs) const;
        bool operator<(Date const &rhs) const;
        bool operator>=(Date const &rhs) const;
        bool operator<=(Date const &rhs) const;

        // Getters
        bool check_date();
        int getDay() const;
        int getMonth() const;
        int getYear() const;
};

// Surcharge de l'opérateur de sortie
std::ostream &operator<<(std::ostream &o, Date const &i);

#endif
