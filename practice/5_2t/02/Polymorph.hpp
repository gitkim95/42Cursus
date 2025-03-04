/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorph.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:29:33 by gitkim            #+#    #+#             */
/*   Updated: 2025/03/04 17:37:00 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POLYMORPH_HPP
# define POLYMORPH_HPP

# include <string>

# include "ASpell.hpp"

class Polymorph : public ASpell
{
public:
	Polymorph( void );
	Polymorph( Polymorph const& other );
	Polymorph&	operator=( Polymorph const& other );
	virtual ~Polymorph();

	virtual Polymorph*	clone( void ) const;
};

#endif