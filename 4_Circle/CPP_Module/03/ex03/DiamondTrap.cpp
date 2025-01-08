/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 00:57:30 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/08 15:58:04 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : ScavTrap(), FragTrap(), name("nonamed")
{
	hitPoints = FragTrap::getHitPoints();
	energyPoints = ScavTrap::getEnergyPoints();
	attackDamage = FragTrap::getAttackDamage();
    std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap( std::string name ) : ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), name(name)
{
	hitPoints = FragTrap::getHitPoints();
	energyPoints = ScavTrap::getEnergyPoints();
	attackDamage = FragTrap::getAttackDamage();
	std::cout << "DiamondTrap parameterized constructor called for: " << name << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap& other ) : ScavTrap(other), FragTrap(other)
{
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap( void )
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

DiamondTrap&	DiamondTrap::operator=( const DiamondTrap& other )
{
	if (this != &other)
	{
		operator=(other);
	}
	std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
	return (*this);
}

std::ostream&	operator<<( std::ostream& out, const DiamondTrap& DiamondTrap )
{
	out	<< "DiamondTrap " << DiamondTrap.name
		<< " [HP: " << DiamondTrap.hitPoints
		<< ", Energy: " << DiamondTrap.energyPoints
		<< ", Attack Damage: " << DiamondTrap.attackDamage
		<< "]";
	return (out);
}

void	DiamondTrap::whoAmI( void )
{
	std::cout << "I am " << name << " and my ClapTrap name is " << FragTrap::getName() << std::endl;
}

void	DiamondTrap::attack( const std::string& target )
{
	ScavTrap::attack(target);
}