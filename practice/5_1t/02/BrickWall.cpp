/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrickWall.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 02:55:56 by gitkim            #+#    #+#             */
/*   Updated: 2025/03/04 04:47:51 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BrickWall.hpp"

BrickWall::BrickWall( void ) : ATarget("Inconspicuous Red-brick Wall") {}

BrickWall::BrickWall( const BrickWall& other ) : ATarget(other) {}

BrickWall::~BrickWall( void ) {}

BrickWall&	BrickWall::operator=( const BrickWall& other )
{
	ATarget::operator=(other);
	return (*this);
}

BrickWall*	BrickWall::clone( void ) const
{
	return (new BrickWall());
}
