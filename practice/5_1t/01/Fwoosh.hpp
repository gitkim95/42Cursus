/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 02:30:36 by gitkim            #+#    #+#             */
/*   Updated: 2025/03/04 03:27:33 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FWOOSH_HPP
# define FWOOSH_HPP

# include "ASpell.hpp"

class Fwoosh : public ASpell
{
public:
	Fwoosh( void );
	Fwoosh( const Fwoosh& other );
	Fwoosh& operator=( const Fwoosh& other );
	~Fwoosh( void );

	virtual Fwoosh*	clone( void ) const;
};

#endif