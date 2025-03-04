/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:36:52 by gitkim            #+#    #+#             */
/*   Updated: 2025/03/04 16:48:39 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"

#include "ASpell.hpp"

ASpell::ASpell( void ) : name("none"), effects("none") {}

ASpell::ASpell( ASpell const& other ) : name(other.name), effects(other.effects) {}

ASpell::ASpell( std::string name, std::string effects ) : name(name), effects(effects) {}

ASpell&	ASpell::operator=( ASpell const& other )
{
	if (this != &other)
	{
		name = other.name;
		effects = other.effects;
	}
	return (*this);
}

ASpell::~ASpell() {}

std::string const&	ASpell::getName( void ) const
{
	return (name);
}

std::string const&	ASpell::getEffects( void ) const
{
	return (effects);
}

void	ASpell::launch( ATarget const& target )
{
	target.getHitBySpell(*this);
}
