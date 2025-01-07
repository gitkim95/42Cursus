/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 00:55:46 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/08 00:55:47 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : name("nonamed"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap( std::string name ) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap parameterized constructor called for: " << name << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& other )
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	name = other.name;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap&	ClapTrap::operator=( const ClapTrap& other )
{
	if (this != &other)
	{
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	return (*this);
}

std::ostream&	operator<<( std::ostream& out, const ClapTrap& clapTrap )
{
	out	<< "ClapTrap " << clapTrap.name
		<< " [HP: " << clapTrap.hitPoints
		<< ", Energy: " << clapTrap.energyPoints
		<< ", Attack Damage: " << clapTrap.attackDamage
		<< "]";
	return (out);
}

void	ClapTrap::attack( const std::string& target )
{
	if (this->energyPoints == 0)
	{
		std::cout	<< name
					<< " has no energy points left!"
					<< std::endl;
		return ;
	}
	std::cout	<< "ClapTrap " 
				<< name
				<< " attacks "
				<< target
				<< ", causing "
				<< attackDamage
				<< " points of damage!"
				<< std::endl;
	this->energyPoints--;
}
void	ClapTrap::takeDamage( unsigned int amount )
{
	std::cout	<< name
				<< " took "
				<< amount
				<< " points of damage!"
				<< std::endl;

	if (this->hitPoints > amount)
		this->hitPoints -= amount;
	else
		this->hitPoints = 0;
}
void	ClapTrap::beRepaired( unsigned int amount )
{
	if (this->energyPoints == 0)
	{
		std::cout	<< name
					<< " has no energy points left!"
					<< std::endl;
		return ;
	}
	std::cout	<< name
				<< " repaired "
				<< amount
				<< " hit points!"
				<< std::endl;

	this->hitPoints += amount;
	this->energyPoints--;
}
std::string	ClapTrap::getName( void )
{
	return (this->name);
}

unsigned int	ClapTrap::getHitPoints( void )
{
	return (this->hitPoints);
}
unsigned int	ClapTrap::getEnergyPoints( void )
{
	return (this->energyPoints);
}

unsigned int	ClapTrap::getAttackDamage( void )
{
	return (this->attackDamage);
}