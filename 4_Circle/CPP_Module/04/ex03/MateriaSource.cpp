/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 21:45:20 by gitkim            #+#    #+#             */
/*   Updated: 2025/02/11 12:47:06 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void )
{
	for (int i = 0; i < 4; i++)
	{
		source[i] = NULL;
	}
}

MateriaSource::MateriaSource( const MateriaSource& other )
{
	for (int i = 0; i < 4; i++)
	{
		if (other.source[i])
			source[i] = other.source[i]->clone();
		else
			source[i] = NULL;
	}
}

MateriaSource::~MateriaSource( void )
{
	for (int i = 0; i < 4; i++)
		delete (source[i]);
}

MateriaSource&	MateriaSource::operator=( const MateriaSource& other )
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (other.source[i])
				source[i] = other.source[i]->clone();
			else
				source[i] = NULL;
		}
	}
	return (*this);
}

void	MateriaSource::learnMateria( AMateria* learn )
{
	for (int i = 0; i < 4; i++)
	{
		if (!source[i])
		{
			source[i] = learn->clone();
			break ;
		}
	}
}

AMateria*	MateriaSource::createMateria( std::string const& type )
{
	for (int i = 0; i < 4; i++)
	{
		if (source[i]->getType() == type)
			return (source[i]->clone());
	}
	return (NULL);
}
