/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:43:23 by gitkim            #+#    #+#             */
/*   Updated: 2025/03/04 18:15:31 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"

#include "SpellBook.hpp"

SpellBook::SpellBook( void ) {}

SpellBook::SpellBook( SpellBook const& other ) : spells(other.spells) {}

SpellBook&	SpellBook::operator=( SpellBook const& other )
{
	if (this != &other)
	{
		spells = other.spells;
	}
	return (*this);
}

SpellBook::~SpellBook()
{
	std::map<std::string, ASpell*>::const_iterator	it = spells.begin();
	std::map<std::string, ASpell*>::const_iterator	temp;
	if (it != spells.end())
	{
		temp = it;
		it++;
		delete (temp->second);
		spells.erase(temp->first);
	}
}

void	SpellBook::learnSpell( ASpell* spell )
{
	spells[spell->getName()] = spell->clone();
}

void	SpellBook::forgetSpell( std::string const& spellName )
{
	std::map<std::string, ASpell*>::const_iterator	it = spells.find(spellName);

	if (it != spells.end())
	{
		delete (it->second);
		spells.erase(spellName);
	}
}

ASpell*	SpellBook::createSpell( std::string const& spellName )
{
	std::map<std::string, ASpell*>::const_iterator	it = spells.find(spellName);

	if (it != spells.end())
	{
		return (it->second->clone());
	}
	return (NULL);
}

std::map<std::string, ASpell*>&	SpellBook::getSpells( void )
{
	return (spells);
}
