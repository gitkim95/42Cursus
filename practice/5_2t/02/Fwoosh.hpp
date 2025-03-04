/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:29:33 by gitkim            #+#    #+#             */
/*   Updated: 2025/03/04 16:53:54 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FWOOSH_HPP
# define FWOOSH_HPP

# include <string>

# include "ASpell.hpp"

class Fwoosh : public ASpell
{
public:
	Fwoosh( void );
	Fwoosh( Fwoosh const& other );
	Fwoosh&	operator=( Fwoosh const& other );
	virtual ~Fwoosh();

	virtual Fwoosh*	clone( void ) const;
};

#endif