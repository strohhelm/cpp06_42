/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:09:13 by pstrohal          #+#    #+#             */
/*   Updated: 2025/01/08 11:57:47 by pstrohal         ###   ########.fr       */
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
	catch (std::exception &e)
	{
		// std::cout <<e.what()<<std::endl;
		return false;
	}
	
	return true ;
}

e_type ScalarConverter::isFloatOrDouble(std::string in, int &decimalPlaces)
{
	int dotCount = 0;
	size_t len = in.length();
	bool fEnd = false;
	if ((in == "+inff") || (in == "inff") ||(in == "-inff") || (in == "nanf"))
		return(FLOAT);
	else if ((in == "+inf") || (in == "inf") ||(in == "-inf") || (in == "nan"))
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
				if (!decimalPlaces)
					decimalPlaces = 1;
				fEnd = true ;
				continue ;
			}
			else
				return INVALID ;
		}
		if (dotCount)
			decimalPlaces++;
	}
	if (!dotCount)
		return INVALID;
	if (fEnd == true)
		return FLOAT ;
	return DOUBLE ;
}


e_type	ScalarConverter::check_type(std::string input, int &decimalPlaces)
{
	e_type type = INVALID;
	
	if (input.size()== 1 && std::isprint(input[0]) && !(std::isdigit(input[0])))
		type = CHAR;
	else if (isInt(input))
		type = INTEGER;
	else
		type = isFloatOrDouble(input, decimalPlaces);
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
	std::cout	<< std::fixed<<std::setprecision(1)
				<<"char: "		<< value.c<<std::endl
				<<"int: "		<< static_cast<int>(value.c)<<std::endl
				<<"float: "		<< static_cast<float>(value.c)<<"f"<<std::endl
				<<"double: "	<< static_cast<double>(value.c)<<std::endl;
	std::cout.unsetf(std::ios::fixed);	//Unset fixed-point formatting
	std::cout.precision(6);				//Reset precision to default
}
void ScalarConverter::convert_int(u_cifd value)
{
	std::cout	<< std::fixed<<std::setprecision(1);
	if (value.i > std::numeric_limits<char>::max() || value.i < std::numeric_limits<char>::min())
			std::cout<<"char: impossible"<<std::endl;
	else
		std::cout<<"char: "<< to_char(static_cast<char>(value.i)) <<std::endl;
	std::cout	<<"int: "<< value.i <<std::endl;
	
	std::cout	<<"float: "		<< static_cast<float>(value.i)<<"f"<<std::endl
				<<"double: "	<< static_cast<double>(value.i)<<std::endl;

	std::cout.unsetf(std::ios::fixed);	//Unset fixed-point formatting
	std::cout.precision(6);				//Reset precision to default
}
void ScalarConverter::convert_float(u_cifd value, int &decimalPlaces)
{
	if (!std::fmod(value.f, static_cast<int>(value.f)))
		std::cout	<<std::fixed<<std::setprecision(1);
	else
	{
		if (decimalPlaces > std::numeric_limits<float>::digits10)
			std::cout<<std::fixed<<std::setprecision(std::numeric_limits<float>::digits10);
		else
			std::cout<<std::fixed<<std::setprecision(decimalPlaces);
	}
	if (std::isnan(value.f) || std::isinf(value.f))
	{
		std::cout<<"char: impossible"<<std::endl;
		std::cout<<"int: impossible"<<std::endl;
	}
	else
	{
		//printing CHAR and check for overflow
		if (value.f > std::numeric_limits<char>::max() || value.f < std::numeric_limits<char>::min())
			std::cout<<"char: impossible"<<std::endl;
		else
			std::cout<<"char: "<<to_char(static_cast<char>(value.f))<<std::endl;
		//printing INTEGER and check for overflow
		if (value.f > (std::numeric_limits<int>::max()) || value.f < std::numeric_limits<int>::min())
			std::cout<<"int: impossible"<<std::endl;
		else
			std::cout<<"int: "<< static_cast<int>(value.f)<<std::endl;
	}
	
	
		std::cout	<<"float: "<< value.f <<"f\n"
					<<"double: "<< static_cast<double>(value.f)<<std::endl;
	std::cout.unsetf(std::ios::fixed);	//Unset fixed-point formatting
	std::cout.precision(6);				//Reset precision to default
}
void ScalarConverter::convert_double(u_cifd value, int &decimalPlaces)
{
	std::cout<<std::fixed;
	//chaeck for NAN or INF
	if (std::isnan(value.d) || std::isinf(value.d))
	{
		std::cout<<"char: impossible"<<std::endl;
		std::cout<<"int: impossible"<<std::endl;
		std::cout	<<"float: "<< static_cast<float>(value.d)<<"f"<<std::endl;
	}
	else
	{
		//printing CHAR and check for overflow
		if (value.d > std::numeric_limits<char>::max() || value.d < std::numeric_limits<char>::min())
			std::cout<<"char: impossible"<<std::endl;
		else
			std::cout<<"char: "<<to_char(static_cast<char>(value.d))<<std::endl;

		//printing INTEGER and check for overflow
		if (value.d > (std::numeric_limits<int>::max()) || value.d < std::numeric_limits<int>::min())
			std::cout<<"int: impossible"<<std::endl;
		else
			std::cout<<"int: "<< static_cast<int>(value.d)<<std::endl;

		if (decimalPlaces > std::numeric_limits<float>::digits10)
			std::cout<<std::setprecision(std::numeric_limits<float>::digits10);
		else if (!std::fmod(value.d, static_cast<int>(value.d)))
			std::cout	<<std::fixed<<std::setprecision(1);
		else
			std::cout<<std::setprecision(decimalPlaces);
		if (value.d > (std::numeric_limits<float>::max()) || value.d < std::numeric_limits<float>::lowest())
				std::cout<<"float: impossible"<<std::endl;
		else
			std::cout	<<"float: "<< static_cast<float>(value.d)<<"f"<<std::endl;
	}
	if (decimalPlaces > std::numeric_limits<double>::digits10)
		std::cout<<std::setprecision(std::numeric_limits<double>::digits10);
	else if (!std::fmod(value.d, static_cast<int>(value.d)))
		std::cout	<<std::fixed<<std::setprecision(1);
	else
		std::cout<<std::setprecision(decimalPlaces);
		std::cout<<"double: "<< value.d <<std::endl;
		std::cout.unsetf(std::ios::fixed);	//Unset fixed-point formatting
		std::cout.precision(6);				//Reset precision to default
}

void ScalarConverter::convert(std::string input)
{
	try{
	u_cifd value;
	int decimalPlaces = 0;
		e_type type = check_type(input, decimalPlaces);
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
				convert_float(value, decimalPlaces);
				break;
			case DOUBLE:
				value.d = std::stod(input);
				convert_double(value, decimalPlaces);
				break;
			default:
				throw "invalid";
		}
	}
	catch (...)
	{
		std::cout<<"INVALID INPUT!"<<std::endl;
	}
}