/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 04:01:24 by gitkim            #+#    #+#             */
/*   Updated: 2025/03/04 04:47:54 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SpellBook.hpp"
#include "ASpell.hpp"

SpellBook::SpellBook( void ) {}

SpellBook::SpellBook( const SpellBook& other ) : skills(other.skills) {}

SpellBook& SpellBook::operator=( const SpellBook& other )
{
	if (this != &other)
	{
		skills = other.skills;
	}
	return (*this);
}

SpellBook::~SpellBook( void )
{
	std::map<std::string, ASpell*>::iterator	it = skills.begin();
	std::map<std::string, ASpell*>::iterator	temp;

	while(it != skills.end())
	{
		temp = it;
		it++;
		delete (temp->second);
		skills.erase(temp);
	}
}

void	SpellBook::learnSpell( ASpell* spell )
{
	skills[spell->getName()] = spell->clone();
}

void	SpellBook::forgetSpell( std::string& spellName )
{
	std::map<std::string, ASpell*>::const_iterator	it = skills.find(spellName);

	if (it != skills.end())
	{
		delete (it->second);
		skills.erase(it);
	}
}

ASpell*	SpellBook::createSpell( std::string& spellName )
{
	std::map<std::string, ASpell*>::const_iterator	it = skills.find(spellName);

	if (it != skills.end())
		return (it->second->clone());
	return (NULL);
}

std::map<std::string, ASpell*>&	SpellBook::getSkills( void )
{
	return (skills);
}