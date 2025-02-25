/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 22:11:06 by maxence           #+#    #+#             */
/*   Updated: 2025/02/25 09:51:07 by mgendrot         ###   ########.fr       */
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
        void _check_date();

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

        // Opérations arithmétiques
        Date &operator+=(int days);
        Date &operator-=(int days);
        Date operator+(int days) const;
        Date operator-(int days) const;

        // Comparaisons
        bool operator==(Date const &rhs) const;
        bool operator!=(Date const &rhs) const;
        bool operator>(Date const &rhs) const;
        bool operator<(Date const &rhs) const;
        bool operator>=(Date const &rhs) const;
        bool operator<=(Date const &rhs) const;

        // Getters
        int getDay() const;
        int getMonth() const;
        int getYear() const;
};

// Surcharge de l'opérateur de sortie
std::ostream &operator<<(std::ostream &o, Date const &i);

#endif
