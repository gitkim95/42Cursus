/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fireball.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 03:52:10 by gitkim            #+#    #+#             */
/*   Updated: 2025/03/04 04:47:46 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fireball.hpp"

Fireball::Fireball( void ) : ASpell("Fireball", "burnt to a crisp") {}

Fireball::Fireball( const Fireball& other ) : ASpell(other) {}

Fireball& Fireball::operator=( const Fireball& other )
{
	ASpell::operator=(other);
	return (*this);
}

Fireball::~Fireball( void ) {}

Fireball*	Fireball::clone( void ) const
{
	return (new Fireball());
}
