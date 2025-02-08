/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 00:55:50 by gitkim            #+#    #+#             */
/*   Updated: 2025/02/08 14:44:57 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap
{
protected:
	std::string		name;
	unsigned int	hitPoints;
	unsigned int	energyPoints;
	unsigned int	attackDamage; 
public:
	ClapTrap( void );
	ClapTrap( std::string name );
	ClapTrap( const ClapTrap& other );
	virtual ~ClapTrap();
	
	ClapTrap&	operator=( const ClapTrap& other );

	virtual void	attack( const std::string& target );
	void			takeDamage( unsigned int amount );
	void			beRepaired( unsigned int amount );

	std::string				getName( void ) const;
	virtual unsigned int	getHitPoints( void ) const;
	virtual unsigned int	getEnergyPoints( void ) const;
	virtual unsigned int	getAttackDamage( void ) const;
};
std::ostream&	operator<<( std::ostream& out, const ClapTrap& ClapTrap );

#endif