/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 00:57:04 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/08 18:35:14 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <string>
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string	name;

public:
	DiamondTrap( void );
	DiamondTrap( std::string name );
	DiamondTrap( const DiamondTrap& other );
	~DiamondTrap();
	
	void	whoAmI( void );
	
	DiamondTrap&			operator=( const DiamondTrap& other );
	friend std::ostream&	operator<<( std::ostream& out, const DiamondTrap& DiamondTrap );

	void	attack( const std::string& target );

	virtual unsigned int	getHitPoints( void ) const;
	virtual unsigned int	getEnergyPoints( void ) const;
	virtual unsigned int	getAttackDamage( void ) const;
};

#endif