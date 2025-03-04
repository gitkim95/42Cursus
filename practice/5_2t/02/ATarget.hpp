/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:29:33 by gitkim            #+#    #+#             */
/*   Updated: 2025/03/04 16:50:05 by gitkim           ###   ########.fr       */
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
	ATarget( ATarget const& other );
	ATarget&	operator=( ATarget const& other );
public:
	ATarget( std::string type );
	virtual ~ATarget();

	std::string const&	getType( void ) const;
	void				getHitBySpell( ASpell const& spell ) const;

	virtual ATarget*	clone( void ) const = 0;
};

#endif