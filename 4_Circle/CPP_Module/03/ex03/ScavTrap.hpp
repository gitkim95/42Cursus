/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 00:56:12 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/08 18:35:03 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap( void );
	ScavTrap( std::string name );
	ScavTrap( const ScavTrap& other );
	~ScavTrap();
	
	void	guardGate( void );
	
	ScavTrap&				operator=( const ScavTrap& other );
	friend std::ostream&	operator<<( std::ostream& out, const ScavTrap& scavTrap );

	void	attack( const std::string& target );

	virtual unsigned int	getHitPoints( void ) const;
	virtual unsigned int	getEnergyPoints( void ) const;
	virtual unsigned int	getAttackDamage( void ) const;
};

#endif