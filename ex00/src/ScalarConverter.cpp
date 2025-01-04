/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:09:13 by pstrohal          #+#    #+#             */
/*   Updated: 2025/01/04 19:55:42 by pstrohal         ###   ########.fr       */
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
	try {
		std::stoi(in);
	}
	catch (...)
	{
		return false;
	}
	return true ;
}

e_type ScalarConverter::isFloatOrDouble(std::string in)
{
	int dotCount = 0;
	size_t len = in.length();
	bool fEnd = false;
	if ((in != "+inff") || (in != "-inff") || (in != "nanf"))
		return(FLOAT);
	else if ((in != "+inf") || (in != "-inf") || (in != "nan"))
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
	{
		try {std::stof(in);}
		catch (...) {return INVALID;}
		return FLOAT ;
	}
	try {std::stod(in);}
	catch (...){return INVALID;}
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

void ScalarConverter::convert_char(u_cifd value)
{
	std::cout<<"char: "<< value.c<<std::endl;
	std::cout<<"int: "<< static_cast<int>(value.c)<<std::endl;
	std::cout<<"float: "<< std::fixed<<std::setprecision(1)<< static_cast<float>(value.c)<<"f"<<std::endl;
	std::cout<<"double: "<< std::fixed<<std::setprecision(1)<< static_cast<double>(value.c)<<std::endl;
}
void ScalarConverter::convert_int(u_cifd value)
{
	std::cout<<"char: "<< to_char(static_cast<char>(value.i)) <<std::endl;
	std::cout<<"int: "<< value.i <<std::endl;
	std::cout<<"float: "<< std::fixed<<std::setprecision(1)<< static_cast<float>(value.i)<<"f"<<std::endl;
	std::cout<<"double: "<< std::fixed<<std::setprecision(1)<< static_cast<double>(value.i)<<std::endl;
}
void ScalarConverter::convert_float(u_cifd value)
{
	std::cout<<"char: "<<to_char(static_cast<char>(value.f))<<std::endl;
	std::cout<<"int: "<< static_cast<int>(value.f)<<std::endl;
	if (!std::fmod(value.d, static_cast<int>(value.d)))
	{
		std::cout	<<std::fixed<<std::setprecision(1)
					<<"float: "<< value.f <<"f\n"
					<<"double: "<< static_cast<double>(value.f)<<std::endl;
	}
	else
	{
		std::cout
			<<"float: "<< value.f <<"f\n"
			<<"double: "<< static_cast<double>(value.f)<<std::endl;
	}

}
void ScalarConverter::convert_double(u_cifd value)
{
	std::cout<<"char: "<<to_char(static_cast<char>(value.d))<<std::endl;
	std::cout<<"int: "<< static_cast<int>(value.d)<<std::endl;
	if (!std::fmod(value.d, static_cast<int>(value.d)))
	{
		std::cout	//<<std::fixed<<std::setprecision(2)
					<<"float: "<< static_cast<float>(value.d)<<"f\n"
					<<"double: "<< value.d <<std::endl;
	}
	else
	{
		std::cout
			<<"float: "<< static_cast<float>(value.d)<<"f\n"
			<<"double: "<< value.d <<std::endl;
	}
}

void ScalarConverter::convert(std::string input)
{
	u_cifd value;
	e_type type = check_type(input);
	switch (type)
	{
		case CHAR:
			value.c = static_cast<char>(input[0]);
			convert_char(value);
			break;
		case INTEGER:
			value.i = std::stoi(input);
			convert_int(value);
			break;
		case FLOAT:
			value.f = std::stof(input);
			convert_float(value);
			break;
		case DOUBLE:
			value.d = std::stod(input);
			convert_double(value);
			break;
		default:
			std::cout<<"INVALID INPUT!"<<std::endl;
	}
}