/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrickWall.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 02:51:50 by gitkim            #+#    #+#             */
/*   Updated: 2025/03/04 04:47:51 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRICKWALL_HPP
# define BRICKWALL_HPP

# include "ATarget.hpp"

class BrickWall : public ATarget
{
public:
	BrickWall( void );
	BrickWall( const BrickWall& other );
	~BrickWall( void );
	BrickWall& operator=( const BrickWall& other );

	virtual BrickWall*	clone( void ) const;
};

#endif