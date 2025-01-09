/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:15:34 by pstrohal          #+#    #+#             */
/*   Updated: 2025/01/09 11:16:41 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <random>
#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"


Base* generate(void)
{
	static std::random_device	device;
	static std::mt19937		generator(device());
	static std::uniform_int_distribution<> distribution(0, 2);

	switch (distribution(generator))
	{
		case 0:
			std::cout <<"A"<<std::endl;
			return new A;
		case 1:
			std::cout <<"B"<<std::endl;
			return new B;
		case 2:
			std::cout <<"C"<<std::endl;
			return new C;
		default:
			std::exit(1);
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A"<<std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B"<<std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C"<<std::endl;
	return;
}

void identify(Base& p)
{
	try {
		(void)dynamic_cast<A&>(p);
		std::cout<<"A"<<std::endl;
		return;
	}
	catch (...){}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout<<"B"<<std::endl;
		return;
	}
	catch (...){}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout<<"C"<<std::endl;
		return;
	}
	catch (...){}
	return;
}

int main (void)
{
	Base *p;
	for (int i = 0; i < 50; i++)
	{
		p = generate();
		identify(p);
		identify(*p);
		std::cout<<std::endl;
		delete p;
		p = nullptr;
	}

	Base ba;
	identify(&ba);

	std::cout<<"========================="<<std::endl;
	identify(generate());
	identify(generate());
	identify(generate());
	std::cout<<"========================="<<std::endl;
	
	A a;
	B b;
	C c;
	identify(&a);
	identify(a);
	std::cout<<"========================="<<std::endl;

	identify(&b);
	identify(b);
	std::cout<<"========================="<<std::endl;

	identify(&c);
	identify(c);
	return 0;
}