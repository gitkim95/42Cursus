/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 02:38:07 by gitkim            #+#    #+#             */
/*   Updated: 2025/03/04 02:51:16 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fwoosh.hpp"

Fwoosh::Fwoosh( void ) : ASpell("Fwoosh", "fwooshed") {}

Fwoosh::Fwoosh( const Fwoosh& other ) : ASpell(other) {}

Fwoosh& Fwoosh::operator=( const Fwoosh& other )
{
	ASpell::operator=(other);
	return (*this);
}

Fwoosh::~Fwoosh( void ) {}

Fwoosh*	Fwoosh::clone( void ) const
{
	return (new Fwoosh());
}
