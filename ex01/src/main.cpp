/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:34:09 by pstrohal          #+#    #+#             */
/*   Updated: 2025/01/14 18:06:52 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"

int main (void)
{
	Data d;
	Data *tmp;
	uintptr_t p;
	
	//Normal Test
	d.str = "Hello this is a stupid subject!";
	p = Serializer::serialize(&d);
	tmp = Serializer::deserialize(p);
	std::cout<<tmp->str<<std::endl;

	std::cout<<"\n===============\n"<<std::endl;
	
	//NullPointer test
	tmp = nullptr;
	p = Serializer::serialize(tmp);
	tmp = Serializer::deserialize(p);
	std::cout<<tmp<<std::endl;

	//Address check
	std::cout<<"\n===============\n"<<std::endl;
	d.str = "Omg this is incredible knowledge right here wohooo!!!";
	std::cout<<&d<<std::endl;
	p = Serializer::serialize(&d);
	tmp = Serializer::deserialize(p);
	std::cout<<tmp<<std::endl;
	std::cout<<tmp->str<<std::endl;

}