/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 00:07:45 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/30 01:49:38 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const std::string	Weapon::getType() const
{
	return (type);
}

void	Weapon::setType( std::string str )
{
	type = str;
}

Weapon::Weapon() : type(NULL) {}

Weapon::Weapon( std::string type ) : type(type) {}

Weapon::~Weapon()
{

}