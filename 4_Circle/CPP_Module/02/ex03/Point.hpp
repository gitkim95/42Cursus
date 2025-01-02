/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 21:15:57 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/02 22:09:15 by gitkim           ###   ########.fr       */
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
public:
	Point( void );
	Point( const float a, const float b );
	Point( const Point& other);
	~Point( void );

	Point&	operator=( const Point& other );

	bool	bsp( Point const a, Point const b, Point const c, Point const point);
};

#endif