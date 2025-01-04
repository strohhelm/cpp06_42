/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:08:49 by pstrohal          #+#    #+#             */
/*   Updated: 2025/01/04 14:46:51 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <limits>

enum s_param
{
	INVALID = -1,
	CHAR,
	INTEGER,
	FLOAT,
	DOUBLE,
};

class ScalarConverter 
{
	private:
		ScalarConverter();
		~ScalarConverter();

	public:
		static void convert(std::string input);
};

#endif