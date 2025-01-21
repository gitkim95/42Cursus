/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 01:20:51 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/22 02:08:16 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <limits>
#include "ScalarConverter.hpp"

static bool	isChar( const std::string& input )
{
	return ();
}

static bool	isInt( const std::string& input )
{

}

static bool isFloat( const std::string& input )
{

}

static bool isDouble( const std::string& input )
{

}

void	ScalarConverter::convert( const std::string& input )
{
	if (input.length() == 1 && !std::isdigit(input[0]))
	{
		char	c = input[0];
		if (std::isprint(input[0]))
		{
			std::cout	<< "char: "
						<< c << std::endl;
		}
		else
			std::cout	<< "char : Non displayable" << std::endl;
		std::cout	<< "int: "
					<< static_cast<int>(c) << std::endl;
		std::cout	<< "float: "
					<< static_cast<float>(c) << "f" << std::endl;
		std::cout	<< "double: "
					<< static_cast<double>(c) << std::endl;
	}
	else if (1)
	{
		try
		{
			/* code */
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
}