/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 21:37:51 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/17 14:37:16 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include "Point.hpp"

bool	Point::bsp( Point const a, Point const b, Point const c, Point const point)
{
	float	triangleArea, abArea, bcArea, caArea;

	triangleArea = std::abs(	a.x.toFloat() * (b.y.toFloat() - c.y.toFloat())
							+	b.x.toFloat() * (c.y.toFloat() - a.y.toFloat())
							+	c.x.toFloat() * (a.y.toFloat() - b.y.toFloat())) / 2;
	abArea = std::abs(	point.x.toFloat() * (a.y.toFloat() - b.y.toFloat())
					+	a.x.toFloat() * (b.y.toFloat() - point.y.toFloat())
					+	b.x.toFloat() * (point.y.toFloat() - a.y.toFloat())) / 2;
	bcArea = std::abs(	point.x.toFloat() * (b.y.toFloat() - c.y.toFloat())
					+	b.x.toFloat() * (c.y.toFloat() - point.y.toFloat())
					+	c.x.toFloat() * (point.y.toFloat() - b.y.toFloat())) / 2;
	caArea = std::abs(	point.x.toFloat() * (c.y.toFloat() - a.y.toFloat())
					+	c.x.toFloat() * (a.y.toFloat() - point.y.toFloat())
					+	a.x.toFloat() * (point.y.toFloat() - c.y.toFloat())) / 2;
	if ((abArea != 0 && bcArea != 0 && caArea != 0) && (std::abs(triangleArea - (abArea + bcArea + caArea)) < 0.0001f))
		return (true);
	else
		return (false);
}