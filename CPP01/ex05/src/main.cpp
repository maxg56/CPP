/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 22:12:57 by max               #+#    #+#             */
/*   Updated: 2025/02/10 22:23:25 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
    std::string	arrayLevel[4] = 
    {"debug", "info", "warning", "error"};
    Harl harl;
    for (int i = 0 ; i < 4; i++)
        harl.complain(arrayLevel[i]);
    return 0;
}
