/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:25:26 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/03 16:30:11 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap
{
private:
	std::string		name;
	unsigned int	hitPoints;
	unsigned int	energyPoints;
	unsigned int	attackDamage; 
public:
	ClapTrap( void );
	ClapTrap( std::string name );
	ClapTrap( const ClapTrap& other );
	~ClapTrap();
	
	ClapTrap&				operator=( const ClapTrap& other );
	friend std::ostream&	operator<<( std::ostream& out, const ClapTrap& ClapTrap );

	void			attack( const std::string& target );
	void			takeDamage( unsigned int amount );
	void			beRepaired( unsigned int amount );

	std::string		getName( void );
	unsigned int	getHitPoints( void );
	unsigned int	getEnergyPoints( void );
	unsigned int	getAttackDamage( void );
};

#endif