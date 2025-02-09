/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 20:39:52 by gitkim            #+#    #+#             */
/*   Updated: 2025/02/09 17:22:04 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cure.hpp"

Cure::Cure( void ) : AMateria()
{
	type = "cure";
}

Cure::Cure( const Cure& other ) : AMateria(other) {}

Cure::~Cure() {}

Cure&	Cure::operator=( const Cure& other )
{
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	return (*this);
}

Cure*	Cure::clone( void ) const
{
	return (new Cure(*this));
}

void	Cure::use( ICharacter& target )
{
	std::cout <<  "* heals" << target.getName() << "’s wounds *" << std::endl;
}
