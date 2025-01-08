/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 00:55:55 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/08 18:38:49 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap()
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap parameterized constructor called for: " << name << std::endl;
}

FragTrap::FragTrap( const FragTrap& other ) : ClapTrap(other)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap::~FragTrap( void )
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap&	FragTrap::operator=( const FragTrap& other )
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	return (*this);
}

std::ostream&	operator<<( std::ostream& out, const FragTrap& FragTrap )
{
	out	<< "FragTrap " << FragTrap.name
		<< " [HP: " << FragTrap.hitPoints
		<< ", Energy: " << FragTrap.energyPoints
		<< ", Attack Damage: " << FragTrap.attackDamage
		<< "]";
	return (out);
}

void	FragTrap::highFivesGuys( void )
{
	std::cout << "Hey, " << name << "! High five!" << std::endl;
}

void	FragTrap::attack( const std::string& target )
{
	if (this->energyPoints == 0)
	{
		std::cout	<< name
					<< " has no energy points left!"
					<< std::endl;
		return ;
	}
	std::cout	<< "FragTrap " 
				<< name
				<< " attacks "
				<< target
				<< ", causing "
				<< attackDamage
				<< " points of damage!"
				<< std::endl;
	this->energyPoints--;
}

unsigned int	FragTrap::getHitPoints( void ) const
{
	return (100);
}

unsigned int	FragTrap::getEnergyPoints( void ) const
{
	return (100);
}

unsigned int	FragTrap::getAttackDamage( void ) const
{
	return (30);
}
