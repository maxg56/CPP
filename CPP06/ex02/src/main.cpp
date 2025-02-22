/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:59:35 by mgendrot          #+#    #+#             */
/*   Updated: 2025/02/22 15:26:25 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "B.hpp"
#include "A.hpp"
#include "C.hpp"

Base* generate(void) 
{
	std::srand(std::time(0));
	int choice = std::rand() % 3;
	
	switch (choice) 
	{
		case 0: return new A();
		case 1: return new B();
		case 2: return new C();
		default:return NULL;
	}
	
	return NULL;
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p) {
	try 
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	} 
	catch (std::exception&) {}
	
	try 
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	} 
	catch (std::exception&) {}
	
	try 
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	} 
	catch (std::exception&) {}
}


int main() {
    Base* instance = generate();
    
    std::cout << "Identifying by pointer: ";
    identify(instance);
    
    std::cout << "Identifying by reference: ";
    identify(*instance);
    
    delete instance;
    return 0;
}
