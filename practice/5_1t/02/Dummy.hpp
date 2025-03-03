/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 02:51:50 by gitkim            #+#    #+#             */
/*   Updated: 2025/03/04 03:08:03 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DUMMY_HPP
# define DUMMY_HPP

# include "ATarget.hpp"

class Dummy : public ATarget
{
public:
	Dummy( void );
	Dummy( const Dummy& other );
	~Dummy( void );
	Dummy& operator=( const Dummy& other );

	virtual Dummy*	clone( void ) const;
};

#endif