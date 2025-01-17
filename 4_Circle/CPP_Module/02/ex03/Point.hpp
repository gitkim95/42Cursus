/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 21:15:57 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/17 14:40:48 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
private:
	const Fixed	x;
	const Fixed	y;
	
	Point&	operator=( const Point& other );
public:
	Point( void );
	Point( const float a, const float b );
	Point( const Point& other);
	~Point( void );


	bool	bsp( Point const a, Point const b, Point const c, Point const point);
};

#endif