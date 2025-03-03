/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 22:57:03 by gitkim            #+#    #+#             */
/*   Updated: 2025/03/03 23:12:17 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATARGET_HPP
# define ATARGET_HPP

# include <string>

class ASpell;

class ATarget
{
private:
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