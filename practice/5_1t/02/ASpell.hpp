/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 21:41:05 by gitkim            #+#    #+#             */
/*   Updated: 2025/03/04 02:49:06 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASPELL_HPP
# define ASPELL_HPP

# include <string>

class ATarget;

class ASpell
{
protected:
	std::string	name;
	std::string effects;
	ASpell( void );
	ASpell( const ASpell& other );
	ASpell& operator=(const ASpell& other );
public:
	ASpell( std::string name, std::string effects );
	virtual ~ASpell();

	std::string const&	getName( void ) const;
	std::string const&	getEffects( void ) const;
	virtual ASpell*		clone( void ) const = 0;
	void				launch( const ATarget& target );
};

#endif