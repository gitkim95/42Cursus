/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 20:36:21 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/13 20:41:32 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice( void );
	Ice( const Ice& other );
	~Ice();

	Ice&	operator=( const Ice& other );

	virtual	Ice*	clone( void ) const;
	virtual	void	use( ICharacter& target );
};

#endif