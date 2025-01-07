/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 00:40:57 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/08 00:40:57 by gitkim           ###   ########.fr       */
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
	
	ClapTrap&				operator=( const ClapTrap& other );
	friend std::ostream&	operator<<( std::ostream& out, const ClapTrap& ClapTrap );

	virtual void	attack( const std::string& target );
	void			takeDamage( unsigned int amount );
	void			beRepaired( unsigned int amount );

	std::string		getName( void );
	unsigned int	getHitPoints( void );
	unsigned int	getEnergyPoints( void );
	unsigned int	getAttackDamage( void );
};

#endif