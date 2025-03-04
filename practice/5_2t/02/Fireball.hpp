/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fireball.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:29:33 by gitkim            #+#    #+#             */
/*   Updated: 2025/03/04 17:37:01 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIREBALL_HPP
# define FIREBALL_HPP

# include <string>

# include "ASpell.hpp"

class Fireball : public ASpell
{
public:
	Fireball( void );
	Fireball( Fireball const& other );
	Fireball&	operator=( Fireball const& other );
	virtual ~Fireball();

	virtual Fireball*	clone( void ) const;
};

#endif