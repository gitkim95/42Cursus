/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 00:57:30 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/08 18:45:13 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : ScavTrap(), FragTrap(), name("nonamed")
{
	hitPoints = getHitPoints();
	energyPoints = getEnergyPoints();
	attackDamage = getAttackDamage();
    std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name)
{
	hitPoints = getHitPoints();
	energyPoints = getEnergyPoints();
	attackDamage = getAttackDamage();
	std::cout << "DiamondTrap parameterized constructor called for: " << name << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap& other ) : ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name)
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

unsigned int	DiamondTrap::getHitPoints( void ) const
{
	return (FragTrap::getHitPoints());
}

unsigned int	DiamondTrap::getEnergyPoints( void ) const
{
	return (ScavTrap::getEnergyPoints());
}

unsigned int	DiamondTrap::getAttackDamage( void ) const
{
	return (FragTrap::getAttackDamage());
}
