/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:29:33 by gitkim            #+#    #+#             */
/*   Updated: 2025/03/04 16:56:05 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DUMMY_HPP
# define DUMMY_HPP

# include <string>

# include "ATarget.hpp"

class Dummy : public ATarget
{
public:
	Dummy( void );
	Dummy( Dummy const& other );
	Dummy&	operator=( Dummy const& other );
	virtual ~Dummy();

	virtual Dummy*	clone( void ) const;
};

#endif