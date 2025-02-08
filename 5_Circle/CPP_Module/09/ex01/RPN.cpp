/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:58:03 by gitkim            #+#    #+#             */
/*   Updated: 2025/02/08 21:29:53 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <string>
#include <exception>
#include "RPN.hpp"

RPN::RPN( void ) {}

RPN::RPN( const RPN &other ) : digit(other.digit) {}

RPN::~RPN( void ) {}

RPN&	RPN::operator=( const RPN &other )
{
	if (this != &other)
		digit = other.digit;
	return (*this);
}

int	RPN::calculate( const std::string &input )
{
	std::istringstream	iss(input);
	std::string			block;
	int					result;

	while (iss >> block)
	{
		std::istringstream	numCheck(block);
		int					num;
		if (numCheck >> num && numCheck.eof())
			digit.push(num);
		else
		{
			if (digit.size() < 2)
				throw (RPNException("Error: Not enough operands"));
			int	second = digit.top();
			digit.pop();
			int	first = digit.top();
			digit.pop();

			switch (block[0])
			{
				case '+':
					result = first + second;
					break;
				case '-':
					result = first - second;
					break;
				case '*':
					result = first * second;
					break;
				case '/':
					if (second == 0)
						throw (RPNException("Error: Division by zero"));
					result = first / second;
					break;
				default:
					throw (RPNException("Error: Invalid operator"));
			}
			digit.push(result);
		}
	}
	if (digit.size() != 1)
		throw (RPNException("Error: Too many operands"));
	return (digit.top());
}

RPN::RPNException::RPNException( const std::string &errMsg ) : errMsg(errMsg) {}

RPN::RPNException::~RPNException() throw() {}

const char* RPN::RPNException::what() const throw()
{
	return (errMsg.c_str());
}