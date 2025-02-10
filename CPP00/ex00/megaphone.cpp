/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 08:40:34 by max               #+#    #+#             */
/*   Updated: 2025/02/10 17:22:36 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <cctype>

int main(int argc, char const *argv[])
{
    int i = 1;
    int j = 0;
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    while (i < argc)
    {
        while (argv[i][j] != '\0')
        {
            std::cout << (char)std::toupper(argv[i][j]);
            j++;
        }
        j = 0;
        i++;
    }
      std::cout << std::endl;
    return 0;
}
