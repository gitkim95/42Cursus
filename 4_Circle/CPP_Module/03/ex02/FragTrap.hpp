/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 00:42:18 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/08 17:21:51 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap( void );
	FragTrap( std::string name );
	FragTrap( const FragTrap& other );
	~FragTrap();
	
	void	highFivesGuys( void );
	
	FragTrap&				operator=( const FragTrap& other );
	friend std::ostream&	operator<<( std::ostream& out, const FragTrap& FragTrap );

	void	attack( const std::string& target );
};


#endif