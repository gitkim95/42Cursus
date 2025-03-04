/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fireball.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:51:37 by gitkim            #+#    #+#             */
/*   Updated: 2025/03/04 17:37:21 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fireball.hpp"

Fireball::Fireball( void ) : ASpell("Fireball", "burnt to a crisp") {}

Fireball::Fireball( Fireball const& other ) : ASpell(other) {}

Fireball&	Fireball::operator=( Fireball const& other )
{
	ASpell::operator=(other);
	return (*this);
}

Fireball::~Fireball(){}

Fireball*	Fireball::clone( void ) const
{
	return (new Fireball());
}
