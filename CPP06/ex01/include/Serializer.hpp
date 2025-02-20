/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 22:36:23 by mgendrot          #+#    #+#             */
/*   Updated: 2025/02/20 23:00:04 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint>
#include <string>
#include <stdint.h>
#include <iostream>

struct Data {
    int value;
    std::string text;
};

class Serializer {
private:
    Serializer(); // Constructeur privé pour empêcher l'instanciation
    Serializer(const Serializer &);
    Serializer &operator=(const Serializer &);

public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif // SERIALIZER_HPP
