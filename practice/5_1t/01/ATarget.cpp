/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 23:05:45 by gitkim            #+#    #+#             */
/*   Updated: 2025/03/03 23:12:20 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ATarget.hpp"
#include "ASpell.hpp"

ATarget::ATarget( std::string type ) : type(type) {}

ATarget::~ATarget() {}

std::string const&	ATarget::getType( void ) const
{
	return (type);
}

void	ATarget::getHitBySpell( const ASpell& spell ) const
{
	std::cout << type << " has been " << spell.getEffects() << "!" << std::endl;
}
