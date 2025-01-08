/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:34:09 by pstrohal          #+#    #+#             */
/*   Updated: 2025/01/08 11:41:49 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"

int main (void)
{
	Data d;
	Data *tmp;
	uintptr_t p;
	
	d.str = "Hello this is a stupid subject!";
	
	p = Serializer::serialize(&d);
	
	tmp = Serializer::deserialize(p);

	std::cout<<tmp->str<<std::endl;
}