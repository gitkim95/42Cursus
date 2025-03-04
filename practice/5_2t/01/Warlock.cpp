/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:20:44 by gitkim            #+#    #+#             */
/*   Updated: 2025/03/04 17:59:43 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ASpell.hpp"

#include "Warlock.hpp"

Warlock::Warlock( void ) : name("nonamed"), title("none") {}

Warlock::Warlock( Warlock const& other ) : name(other.name), title(other.title) {}

Warlock::Warlock( std::string name, std::string title ) : name(name), title(title)
{
	std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock&	Warlock::operator=( Warlock const& other )
{
	if (this != &other)
	{
		name = other.name;
		title = other.title;
	}
	return (*this);
}

Warlock::~Warlock()
{
	std::cout << name << ": My job here is done!" << std::endl;

	std::map<std::string, ASpell*>::const_iterator	it = spells.begin();
	std::map<std::string, ASpell*>::const_iterator	temp;
	while (it != spells.end())
	{
		temp = it;
		it++;
		delete (temp->second);
		spells.erase(temp);
	}
}

std::string const&	Warlock::getName( void ) const
{
	return (name);
}

std::string const&	Warlock::getTitle( void ) const
{
	return (title);
}

void	Warlock::setTitle( std::string const& newTitle )
{
	title = newTitle;
}

void	Warlock::introduce( void ) const
{
	std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}

void	Warlock::learnSpell( ASpell* spell )
{
	spells[spell->getName()] = spell;
}

void	Warlock::forgetSpell( std::string const& spellName )
{
	std::map<std::string, ASpell*>::const_iterator	it = spells.find(spellName);

	if (it != spells.end())
	{
		delete (it->second);
		spells.erase(spellName);
	}
}

void	Warlock::launchSpell( std::string const& spellName, ATarget& target )
{
	std::map<std::string, ASpell*>::const_iterator	it = spells.find(spellName);

	if (it != spells.end())
	{
		it->second->launch(target);
	}
}
