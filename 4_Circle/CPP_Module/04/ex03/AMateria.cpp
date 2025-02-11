/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:22:21 by gitkim            #+#    #+#             */
/*   Updated: 2025/02/11 12:36:36 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"

AMateria::AMateria( void ) : type("untyped") {}

AMateria::AMateria( std::string const &type ) : type(type) {}

AMateria::AMateria( const AMateria& other ) : type(other.type) {}

AMateria::~AMateria() {}

AMateria&	AMateria::operator=( const AMateria& other )
{
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

std::string const& AMateria::getType( void ) const
{
	return (type);
}

void AMateria::use( ICharacter& target )
{
	static_cast<void>(target);
	std::cout << "* There is no type *" << std::endl;
}
