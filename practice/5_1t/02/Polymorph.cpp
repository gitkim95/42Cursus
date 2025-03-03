/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorph.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 03:52:22 by gitkim            #+#    #+#             */
/*   Updated: 2025/03/04 04:48:17 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorph.hpp"

Polymorph::Polymorph( void ) : ASpell("Polymorph", "turned into a critter") {}

Polymorph::Polymorph( const Polymorph& other ) : ASpell(other) {}

Polymorph& Polymorph::operator=( const Polymorph& other )
{
	ASpell::operator=(other);
	return (*this);
}

Polymorph::~Polymorph( void ) {}

Polymorph*	Polymorph::clone( void ) const
{
	return (new Polymorph());
}
