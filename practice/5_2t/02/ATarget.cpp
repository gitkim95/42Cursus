/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:36:52 by gitkim            #+#    #+#             */
/*   Updated: 2025/03/04 16:48:37 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ASpell.hpp"

#include "ATarget.hpp"

ATarget::ATarget( void ) : type("none") {}

ATarget::ATarget( ATarget const& other ) : type(other.type) {}

ATarget::ATarget( std::string type ) : type(type) {}

ATarget&	ATarget::operator=( ATarget const& other )
{
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

ATarget::~ATarget() {}

std::string const&	ATarget::getType( void ) const
{
	return (type);
}

void	ATarget::getHitBySpell( ASpell const& spell ) const
{
	std::cout << type << " has been " << spell.getEffects() << "!" << std::endl;
}
