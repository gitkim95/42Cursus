/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fireball.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 03:49:51 by gitkim            #+#    #+#             */
/*   Updated: 2025/03/04 04:47:36 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIREBALL_HPP
# define FIREBALL_HPP

# include "ASpell.hpp"

class Fireball : public ASpell
{
public:
	Fireball( void );
	Fireball( const Fireball& other );
	Fireball& operator=( const Fireball& other );
	~Fireball( void );

	virtual Fireball*	clone( void ) const;
};


#endif