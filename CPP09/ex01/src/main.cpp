/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:24:21 by mgendrot          #+#    #+#             */
/*   Updated: 2025/02/25 14:57:06 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: rpn_calculator <expression>" << std::endl;
        return 1;
    }

    std::string input = argv[1];
    RPN calculator;
    calculator.calculate(input);

    return 0;
}