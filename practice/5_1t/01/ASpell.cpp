/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 23:05:26 by gitkim            #+#    #+#             */
/*   Updated: 2025/03/04 02:45:57 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"
#include "ATarget.hpp"

ASpell::ASpell( void ) : name("none"), effects("none") {}

ASpell::ASpell( const ASpell& other ) : name(other.name), effects(other.effects) {}

ASpell::ASpell( std::string name, std::string effects ) : name(name), effects(effects) {}

ASpell::~ASpell() {}

ASpell& ASpell::operator=( const ASpell& other )
{
	if (this != &other)
	{
		name = other.name;
		effects = other.effects;
	}
	return (*this);
}

std::string const&	ASpell::getName( void ) const
{
	return (name);
}

std::string const&	ASpell::getEffects( void ) const
{
	return (effects);
}

void	ASpell::launch( const ATarget& target )
{
	target.getHitBySpell(*this);
}
