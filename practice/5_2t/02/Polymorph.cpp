/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorph.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:51:37 by gitkim            #+#    #+#             */
/*   Updated: 2025/03/04 17:37:43 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorph.hpp"

Polymorph::Polymorph( void ) : ASpell("Polymorph", "turned into a critter") {}

Polymorph::Polymorph( Polymorph const& other ) : ASpell(other) {}

Polymorph&	Polymorph::operator=( Polymorph const& other )
{
	ASpell::operator=(other);
	return (*this);
}

Polymorph::~Polymorph(){}

Polymorph*	Polymorph::clone( void ) const
{
	return (new Polymorph());
}
