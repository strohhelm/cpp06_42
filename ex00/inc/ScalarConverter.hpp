/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:08:49 by pstrohal          #+#    #+#             */
/*   Updated: 2025/01/04 16:57:02 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <limits>

typedef enum s_param
{
	INVALID = -1,
	CHAR,
	INTEGER,
	FLOAT,
	DOUBLE,
} e_type;

class ScalarConverter 
{
	private:
		ScalarConverter();
		~ScalarConverter();
		static e_type	check_type(std::string input);
		static e_type	isFloatOrDouble(std::string in);
		static bool	isInt(std::string in);


	public:
		static void convert(std::string input);
};

#endif