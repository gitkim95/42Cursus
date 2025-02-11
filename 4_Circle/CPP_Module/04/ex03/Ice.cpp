/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 20:41:43 by gitkim            #+#    #+#             */
/*   Updated: 2025/02/11 12:40:09 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ICharacter.hpp"
#include "Ice.hpp"

Ice::Ice( void ) : AMateria()
{
	type = "ice";
}

Ice::Ice( const Ice& other ) : AMateria(other) {}

Ice::~Ice() {}

Ice&	Ice::operator=( const Ice& other )
{
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	return (*this);
}

Ice*	Ice::clone( void ) const
{
	return (new Ice(*this));
}

void	Ice::use( ICharacter& target )
{
	std::cout <<  "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
