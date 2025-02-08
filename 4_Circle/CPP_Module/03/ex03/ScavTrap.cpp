/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 00:56:08 by gitkim            #+#    #+#             */
/*   Updated: 2025/02/08 14:41:23 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap()
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap parameterized constructor called for: " << name << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap& other ) : ClapTrap(other)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap&	ScavTrap::operator=( const ScavTrap& other )
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	return (*this);
}

std::ostream&	operator<<( std::ostream& out, const ScavTrap& scavTrap )
{
	out	<< "ScavTrap " << scavTrap.getName()
		<< " [HP: " << scavTrap.getHitPoints()
		<< ", Energy: " << scavTrap.getEnergyPoints()
		<< ", Attack Damage: " << scavTrap.getAttackDamage()
		<< "]";
	return (out);
}

void	ScavTrap::guardGate( void )
{
	std::cout << name << " is in Gate keeper mode" << std::endl;
}

void	ScavTrap::attack( const std::string& target )
{
	if (this->energyPoints == 0)
	{
		std::cout	<< name
					<< " has no energy points left!"
					<< std::endl;
		return ;
	}
	std::cout	<< "ScavTrap " 
				<< name
				<< " attacks "
				<< target
				<< ", causing "
				<< attackDamage
				<< " points of damage!"
				<< std::endl;
	this->energyPoints--;
}
