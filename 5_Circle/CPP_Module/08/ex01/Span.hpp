/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:07:35 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/26 18:14:52 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>

class Span
{
private:
	unsigned int		N;
	std::vector<int>	vec;
public:
	Span( void );
	Span( unsigned int n );
	Span( const Span& other );
	~Span();

	Span&	operator=( const Span& other );

	void	addNumber( int value );
	int		shortestSpan( void );
	int		longestSpan( void );
};

#endif