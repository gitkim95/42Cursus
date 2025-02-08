/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 00:41:09 by gitkim            #+#    #+#             */
/*   Updated: 2025/02/08 14:27:14 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap( void );
	ScavTrap( std::string name );
	ScavTrap( const ScavTrap& other );
	~ScavTrap();
	
	void	guardGate( void );
	
	ScavTrap&	operator=( const ScavTrap& other );

	void	attack( const std::string& target );
};
std::ostream&	operator<<( std::ostream& out, const ScavTrap& scavTrap );

#endif