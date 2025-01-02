/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 21:29:41 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/02 21:37:37 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ) : x(), y() {}

Point::Point( const float a, const float b) : x(a), y(b) {}

Point::Point( const Point& other ) : x(other.x), y(other.y) {}

Point::~Point( void ) {}

Point&	Point::operator=( const Point& other ) = delete;
