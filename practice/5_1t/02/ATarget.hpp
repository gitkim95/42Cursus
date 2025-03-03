/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 22:57:03 by gitkim            #+#    #+#             */
/*   Updated: 2025/03/04 02:52:50 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATARGET_HPP
# define ATARGET_HPP

# include <string>

class ASpell;

class ATarget
{
protected:
	std::string	type;
	ATarget( void );
	ATarget( const ATarget& other );
	ATarget& operator=( const ATarget& other );
public:
	ATarget( std::string type );
	virtual ~ATarget();

	std::string const&	getType( void ) const;
	virtual ATarget*	clone( void ) const = 0;
	void				getHitBySpell( const ASpell& spell ) const;
};

#endif