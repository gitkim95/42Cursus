/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:12:28 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/26 18:52:51 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <climits>
#include "Span.hpp"

Span::Span( void ) : N(0) {}

Span::Span( unsigned int n ) : N(n) {}

Span::Span( const Span& other ) : N(other.N), vec(other.vec) {}

Span::~Span() {}

Span&	Span::operator=( const Span& other )
{
	if (this != &other)
	{
		N = other.N;
		vec = other.vec;
	}
	return (*this);
}

void	Span::addNumber( int value )
{
	if (vec.size() >= N)
		throw (std::overflow_error("Span is full."));
	vec.push_back(value);
}

int	Span::shortestSpan( void )
{
	if (vec.size() < 2)
		throw (std::logic_error("Span length is less than 2, comparison not possible"));
	std::sort(vec.begin(), vec.end());
	int	minSpan = INT_MAX;
	for (size_t i = 1; i < vec.size(); i++)
	{
		minSpan = std::min(minSpan, vec[i] - vec[i - 1]);
	}
	return (minSpan);
}

int	Span::longestSpan( void )
{
	if (vec.size() < 2)
		throw (std::logic_error("Span length is less than 2, comparison not possible"));
	std::sort(vec.begin(), vec.end());
	int maxValue = *std::max_element(vec.begin(), vec.end());
	int	minValue = *std::min_element(vec.begin(), vec.end());
	return (maxValue - minValue);
}
