/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 21:29:05 by gitkim            #+#    #+#             */
/*   Updated: 2025/03/04 03:27:01 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ASpell.hpp"
#include "Warlock.hpp"

Warlock::Warlock( std::string name, std::string title ) : name(name), title(title)
{
	std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << name << ": My job here is done!" << std::endl;
	std::map<std::string, ASpell*>::iterator	it = skill.begin();
	std::map<std::string, ASpell*>::iterator	temp;
	while (it != skill.end())
	{
		temp = it;
		it++;
		delete (temp->second);
		skill.erase(temp);
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

void	Warlock::introduce() const
{
	std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}

void	Warlock::learnSpell( ASpell* spell )
{
	skill[spell->getName()] = spell;
}

void	Warlock::forgetSpell( std::string spellName )
{
	std::map<std::string, ASpell*>::const_iterator	it = skill.find(spellName);

	if (it != skill.end())
	{
		delete (it->second);
		skill.erase(it);
	}
}

void	Warlock::launchSpell( std::string spellName, ATarget& target )
{
	std::map<std::string, ASpell*>::const_iterator	it = skill.find(spellName);

	if (it != skill.end())
	{
		it->second->launch(target);
	}
}
