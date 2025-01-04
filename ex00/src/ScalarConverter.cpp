/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConveter.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@42.heilbronn.de>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-19 22:09:13 by pstrohal          #+#    #+#             */
/*   Updated: 2024-12-19 22:09:13 by pstrohal         ###   ########.fr       */
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


bool isInt(std::string in)
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

int isFloatOrDouble(std::string in)
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


int	check_type(std::string input)
{
	int i = INVALID;
	
	if (input.size()== 1 && std::isprint(input[0]))
		i = CHAR;
	else if (isInt(input))
		i = INTEGER;
	else
		i = isFloatOrDouble(input);
	return i;
}

std::string to_char(int i)
{
	std::string str;
	((i >= 32 && i <= 126)) ? (str = (char)i) : (str = "Non displayable");
	return str;
}

void ScalarConverter::convert(std::string input)
{
	std::string tmp = input;
	int i = check_type(input);
	
	if (i != CHAR)
	{
		std::cout<<"char: ";
		try {std::cout<<to_char(std::stoi(input))<<std::endl;}
		catch (...){std::cout<<"impossible"<<std::endl;}
	}
	if (i != INTEGER)
	{
		std::cout<<"int: ";
		try {std::cout<<std::stoi(input)<<"\n";}
		catch (...){std::cout<<"impossible\n";}
	}
	if ( i != FLOAT)
	{
		std::cout<<"float: ";
		try {std::cout<<std::stof(input) <<"f\n";}
		catch(...){std::cout<<"impossible"<<std::endl;}
	}
	if (i != DOUBLE)
	{
		std::cout<<"double: ";
		try {std::cout<<std::stod(input)<<std::endl;}
		catch(...){std::cout<<"impossible"<<std::endl;}
	}
	return ;
}