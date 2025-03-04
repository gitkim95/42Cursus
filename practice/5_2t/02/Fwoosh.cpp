/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:51:37 by gitkim            #+#    #+#             */
/*   Updated: 2025/03/04 16:55:15 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fwoosh.hpp"

Fwoosh::Fwoosh( void ) : ASpell("Fwoosh", "fwooshed") {}

Fwoosh::Fwoosh( Fwoosh const& other ) : ASpell(other) {}

Fwoosh&	Fwoosh::operator=( Fwoosh const& other )
{
	ASpell::operator=(other);
	return (*this);
}

Fwoosh::~Fwoosh(){}

Fwoosh*	Fwoosh::clone( void ) const
{
	return (new Fwoosh());
}
