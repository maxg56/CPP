/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 22:38:09 by mgendrot          #+#    #+#             */
/*   Updated: 2025/02/20 23:00:21 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Serializer.hpp"


int main() {
    Data data = {42, "Hello, World!"};

    std::cout << "Original Data pointer: " << &data << std::endl;

   	uintptr_t* raw = Serializer::serialize(&data);
    std::cout << "Serialized value: " << raw << std::endl;

    Data* deserializedData = Serializer::deserialize(raw);
    std::cout << "Deserialized Data pointer: " << deserializedData << std::endl;

    if (deserializedData == &data) {
        std::cout << "Serialization and deserialization successful!" << std::endl;
        std::cout << "Data value: " << deserializedData->value << std::endl;
        std::cout << "Data text: " << deserializedData->text << std::endl;
    } else {
        std::cout << "Error: pointers do not match!" << std::endl;
    }

    return 0;
}
