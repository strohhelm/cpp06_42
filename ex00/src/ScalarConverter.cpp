/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:09:13 by pstrohal          #+#    #+#             */
/*   Updated: 2025/01/04 17:17:17 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/ScalarConverter.hpp"

/* ************************************************************************** */
/*		CONSTRUCTORS, DESTRUCTORS											  */
/* ************************************************************************** */

//Default constructor

ScalarConverter::ScalarConverter(){}


/* ************************************************************************** */
/*			MEMBER FUNCTIONS												  */
/* ************************************************************************** */


bool ScalarConverter::isInt(std::string in)
{
	size_t len = in.length();
	for(size_t i = 0; i < len; i++)
	{
		if (i == 0 && (in[i] == '+' || in[i] == '-'))
			continue ;
		if (!std::isdigit(in[i]))
			return false ;
	}
	return true ;
}

e_type ScalarConverter::isFloatOrDouble(std::string in)
{
	int dotCount = 0;
	size_t len = in.length();
	bool fEnd = false;
	if (!in.compare("+inff") || !in.compare("-inff") || !in.compare("nanf"))
		return(FLOAT);
	else if (!in.compare("+inf") || !in.compare("-inf") || !in.compare("nan"))
		return (DOUBLE);
	for(size_t i = 0; i < len; i++)
	{
		if (i == 0 && (in[i] == '+' || in[i] == '-'))
			continue ;
		if (!std::isdigit(in[i]))
		{
			if (in[i] == '.')
			{
				dotCount++;
				if (dotCount > 1)
					return INVALID ;
				else
					continue ;
			}
			else if (i == len - 1 && in[i] == 'f'){
				fEnd = true ;
				continue ;
			}
			else
				return INVALID ;
		}
	}
	if (fEnd == true)
		return FLOAT ;
	return DOUBLE ;
	
}


e_type	ScalarConverter::check_type(std::string input)
{
	e_type type = INVALID;
	
	if (input.size()== 1 && std::isprint(input[0]))
		type = CHAR;
	else if (isInt(input))
		type = INTEGER;
	else
		type = isFloatOrDouble(input);
	return type;
}

std::string to_char(int i)
{
	std::string str;
	((i >= 32 && i <= 126)) ? (str = (char)i) : (str = "Non displayable");
	return str;
}

void ScalarConverter::convert(std::string input)
{
	char	c;
	int		i;
	float	f;
	double	d;
	e_type type = check_type(input);
	switch (type)
	{
		case CHAR:
			c = 
	}
	std::cout<<"char: ";
	if (i != CHAR)
	{
		
	}
	else
		std::cout<<input<<std::endl;

	std::cout<<"int: ";
	if (i != INTEGER)
	{
	
	}
	else
		std::cout<<input<<std::endl;

	std::cout<<"float: ";
	if ( i != FLOAT)
	{
		
	}
	else
		std::cout<<input<<std::endl;

	std::cout<<"double: ";
	if (i != DOUBLE)
	{
	
	}
	else
		std::cout<<input<<std::endl;
	return ;
}