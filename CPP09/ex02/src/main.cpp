/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 22:24:47 by mgendrot          #+#    #+#             */
/*   Updated: 2025/02/26 23:16:37 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac , char **av){
    try{
        if(ac > 2){
            PmergeMe<std::deque<int > > Deque(av);
            PmergeMe<std::vector<int > > Vector(av);

            std::cout << "Before: " << Deque << std::endl;
            Deque.sort();
            Vector.sort();
            std::cout << "After: " << Deque << std::endl;
            
            Deque.sort_time();
            Vector.sort_time();

        }
        else 
            throw "1";
    }catch(...){
        std::cerr << "Error" << std::endl;
    }
    return 0;
}