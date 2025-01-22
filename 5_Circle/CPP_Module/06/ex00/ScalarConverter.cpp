/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 01:20:51 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/22 23:12:27 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <iomanip>
#include "ScalarConverter.hpp"

ScalarConverter::~ScalarConverter( void ) {}

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
		char*	end = NULL;
		std::strtof(input.c_str(), &end);
		return (*end == 'f' && *(end + 1) == '\0');
	}
	return (false);
}

static bool isDouble( const std::string& input )
{
	char*	end = NULL;
	if (input == "nan" || input == "+inf" || input == "-inf" || input == "inf")
		return (true);
	std::strtod(input.c_str(), &end);
	return (*end == '\0');
}

void	ScalarConverter::convert( const std::string& input )
{
	char	*end = NULL;
	
	if (isChar(input))
	{
		char	c = input[0];

		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
	}
	else if (isInt(input))
	{
		long	i = std::strtol(input.c_str(), &end, 10);

		std::cout << "char: " << (std::isprint(i) ? "'" + std::string(1, static_cast<char>(i)) + "'" : "Non displayable") << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(i) << std::endl;
	}
	else if (isFloat(input))
	{
		float	f = std::strtof(input.c_str(), &end);

		std::cout << "char: " << (std::isprint(static_cast<int>(f)) ? "'" + std::string(1, static_cast<char>(f)) + "'" : "impossible") << std::endl;
		std::cout << "int: " << static_cast<int>(f) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl;
	}
	else if (isDouble(input))
	{
		double	d = std::strtod(input.c_str(), &end);

		if (input == "nan" || input == "inf" || input == "-inf" || input == "+inf")
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
		}
		else
		{
			std::cout << "char: " << (std::isprint(static_cast<int>(d)) ? "'" + std::string(1, static_cast<char>(d)) + "'" : "impossible") << std::endl;
			std::cout << "int: " << static_cast<int>(d) << std::endl;
		}
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}
