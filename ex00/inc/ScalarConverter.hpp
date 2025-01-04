/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:08:49 by pstrohal          #+#    #+#             */
/*   Updated: 2025/01/04 19:42:47 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <limits>
#include <iomanip>

typedef enum s_param
{
	INVALID = -1,
	CHAR,
	INTEGER,
	FLOAT,
	DOUBLE,
} e_type;

typedef union u_charintfloatdouble
{
	char c;
	int i;
	float f;
	double d;
}u_cifd;

class ScalarConverter 
{
	private:
		ScalarConverter();
		~ScalarConverter();
		static e_type	check_type(std::string input);
		static e_type	isFloatOrDouble(std::string in);
		static bool	isInt(std::string in);
		static void convert_char(u_cifd value);
		static void convert_int(u_cifd value);
		static void convert_float(u_cifd value);
		static void convert_double(u_cifd value);

	public:
		static void convert(std::string input);
};

#endif