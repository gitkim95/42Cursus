/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorph.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 03:50:50 by gitkim            #+#    #+#             */
/*   Updated: 2025/03/04 04:48:18 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POLYMORPH_HPP
# define POLYMORPH_HPP

# include "ASpell.hpp"

class Polymorph : public ASpell
{
public:
	Polymorph( void );
	Polymorph( const Polymorph& other );
	Polymorph& operator=( const Polymorph& other );
	~Polymorph( void );

	virtual Polymorph*	clone( void ) const;
};


#endif