/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:15:34 by pstrohal          #+#    #+#             */
/*   Updated: 2025/01/08 18:35:49 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <random>
// #include <cstdlib>
#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"


Base* generate(void)
{
	static std::random_device	rd;
	static std::mt19937		gen(rd);
	static std::uniform_int_distribution<int> dis(0, 2);
	
	switch (dis(gen))
	{
		case 0:
			std::cout <<"generated obj of A"<<std::endl;
			return new A;
		case 1:
			std::cout <<"generated obj of B"<<std::endl;
			return new B;
		case 2:
			std::cout <<"generated obj of C"<<std::endl;
			return new C;
		default:
			std::exit(1);
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Pointer is a A ClassPointer"<<std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Pointer is a B ClassPointer"<<std::endl;
	else
		std::cout << "Pointer is a C ClassPointer"<<std::endl;
	return;
}


void identify(Base& p)
{
	try {
		(void)dynamic_cast<A&>(p);
		std::cout<<"This is a reference to an object of A"<<std::endl;
	}
	catch (...){}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout<<"This is a reference to an object of B"<<std::endl;
	}
	catch (...){}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout<<"This is a reference to an object of C"<<std::endl;
	}
	catch (...){}
	return;
}

int main (void)
{
	Base *p;
	for (int i = 0; i < 20; i++)
	{
		p = generate();
		identify(p);
		identify(*p);
		delete p;
		p = nullptr;
	}
	return 0;
}