/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrickWall.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:51:37 by gitkim            #+#    #+#             */
/*   Updated: 2025/03/04 17:39:29 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BrickWall.hpp"

BrickWall::BrickWall( void ) : ATarget("Inconspicuous Red-brick Wall") {}

BrickWall::BrickWall( BrickWall const& other ) : ATarget(other) {}

BrickWall&	BrickWall::operator=( BrickWall const& other )
{
	ATarget::operator=(other);
	return (*this);
}

BrickWall::~BrickWall(){}

BrickWall*	BrickWall::clone( void ) const
{
	return (new BrickWall());
}
