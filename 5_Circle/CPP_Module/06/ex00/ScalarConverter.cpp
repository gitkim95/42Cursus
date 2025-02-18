/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 01:20:51 by gitkim            #+#    #+#             */
/*   Updated: 2025/02/18 23:17:27 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <iomanip>
#include "ScalarConverter.hpp"

ScalarConverter::~ScalarConverter( void ) {}

static bool	isInCharRange( const double& input )
{
	return (input >= 0 && input <= 255);
}

static bool	isInIntRange( const double& input )
{
	return (input >= std::numeric_limits<int>::min() && input <= std::numeric_limits<int>::max());
}

static bool	isSpecialFloatingPointFloat( const std::string& input )
{
	return (input == "nanf" || input == "+inff" || input == "-inff" || input == "inff");
}

static bool	isSpecialFloatingPointDouble( const std::string& input )
{
	return (input == "nan" || input == "+inf" || input == "-inf" || input == "inf");
}

static bool	isChar( const std::string& input )
{
	return (input.length() == 1 && !std::isdigit(input[0]));
}

static bool	isInt( const std::string& input )
{
	char*	end = NULL;
	long	value = std::strtol(input.c_str(), &end, 10);
	return (*end == '\0' && value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max());
}

static bool isFloat( const std::string& input )
{
	if (input.find('f') != std::string::npos && input[input.size() - 1] == 'f')
	{
		if (isSpecialFloatingPointFloat(input))
			return (true);
		char*	end = NULL;
		std::strtof(input.c_str(), &end);
		return (*end == 'f' && *(end + 1) == '\0');
	}
	return (false);
}

static bool isDouble( const std::string& input )
{
	char*	end = NULL;
	if (isSpecialFloatingPointDouble(input))
		return (true);
	std::strtod(input.c_str(), &end);
	return (*end == '\0');
}

static void	printChar( const std::string& input, const value& value )
{
	if (!isInCharRange(value.d))
		std::cout << "char: impossible";
	else if (isChar(input))
		std::cout << "char: '" << value.c << "'";
	else if (isInt(input))
	{
		std::cout << "char: ";
		if (isInCharRange(value.i) && std::isprint(value.i))
			std::cout << "'" + std::string(1, static_cast<char>(value.i)) + "'";
		else
			std::cout << "Non displayable";
	}
	else if (isFloat(input) || isDouble(input))
	{
		if (isSpecialFloatingPointFloat(input) || isSpecialFloatingPointDouble(input))
			std::cout << "char: impossible";
		else
		{
			std::cout << "char: ";
			if (isInCharRange(value.d) && std::isprint(static_cast<int>(value.d)))
				std::cout << "'" + std::string(1, static_cast<char>(value.d)) + "'";
			else
				std::cout << "Non displayable";
		}
	}
	else
		std::cout << "char: impossible";
	std::cout << std::endl;
}

static void	printInt( const std::string& input, const value& value )
{
	std::cout << "int: ";
	if (!isInIntRange(value.d))
		std::cout << "impossible";
	else if (isChar(input))
		std::cout << static_cast<int>(value.c);
	else if (isInt(input) || isFloat(input) || isDouble(input))
	{
		if (isSpecialFloatingPointFloat(input) || isSpecialFloatingPointDouble(input))
			std::cout << "impossible";
		else
			std::cout << static_cast<int>(value.i);
	}
	else
		std::cout << "impossible";
	std::cout << std::endl;
}

static void	printFloat( const std::string& input, const value& value )
{
	std::cout << "float: ";
	if (isChar(input))
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value.c) << "f";
	else if (isInt(input) || isFloat(input) || isDouble(input))
		std::cout << std::fixed << std::setprecision(1) << value.f << "f";
	else
		std::cout << "impossible";
	std::cout << std::endl;
}

static void	printDouble( const std::string& input, const value& value )
{
	std::cout << "double: ";
	if (isChar(input))
		std::cout << std::fixed << std::setprecision(1) << static_cast<double>(value.c);
	else if (isInt(input) || isFloat(input) || isDouble(input))
		std::cout << std::fixed << std::setprecision(1) << value.d;
	else
		std::cout << "impossible";
	std::cout << std::endl;
}

static void	convertInput( const std::string& input, value& value )
{
	char*	end;
	value.c = input[0];
	value.i = std::strtol(input.c_str(), &end, 10);
	value.f = std::strtof(input.c_str(), &end);
	value.d = std::strtod(input.c_str(), &end);
}

void	ScalarConverter::convert( const std::string& input )
{
	value	value;
	convertInput(input, value);
	
	printChar(input, value);
	printInt(input, value);
	printFloat(input, value);
	printDouble(input, value);
}
