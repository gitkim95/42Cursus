/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 00:07:30 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/29 20:57:50 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"
#include "Weapon.hpp"

void	HumanB::attack()
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}

void	HumanB::setWeapon( std::string newWeapon )
{
	weapon.setType(newWeapon);
}

HumanB::HumanB( std::string& name ) : name(name), weapon(NULL) {}

HumanB::~HumanB() {}

