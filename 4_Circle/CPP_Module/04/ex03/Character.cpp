/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 21:13:53 by gitkim            #+#    #+#             */
/*   Updated: 2025/02/11 12:37:18 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character( void ) : name("unnamed")
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character( const std::string& name ) : name(name)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character( const Character &other ) : name(other.name)
{
	for (int i = 0; i < 4; i++)
	{
		if (other.inventory[i])
			inventory[i] = other.inventory[i]->clone();
		else
			inventory[i] = NULL;
	}
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		delete (inventory[i]);
}

Character&	Character::operator=( const Character &other )
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (other.inventory[i])
				inventory[i] = other.inventory[i]->clone();
			else
				inventory[i] = NULL;
		}
	}
	return (*this);
}

std::string const&	Character::getName( void ) const
{
	return (name);
}

void	Character::equip( AMateria* m )
{
	for (int i = 0; i < 4; i++)
	{
		if (!inventory[i])
		{
			inventory[i] = m;
			return ;
		}
	}
}

void	Character::unequip( int idx )
{
	if (idx < 0 || idx > 3 || !inventory[idx])
		return ;
	inventory[idx] = NULL;
}

void	Character::use( int idx, ICharacter& target )
{
	if (idx < 0 || idx > 3 || !inventory[idx])
		return ;
	inventory[idx]->use(target);
}

AMateria*	Character::getMateria( int idx )
{
	if (idx < 0 || idx > 3 || !inventory[idx])
		return (NULL);
	return (inventory[idx]);
}
