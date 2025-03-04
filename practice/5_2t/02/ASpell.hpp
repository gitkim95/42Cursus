/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:29:33 by gitkim            #+#    #+#             */
/*   Updated: 2025/03/04 16:49:58 by gitkim           ###   ########.fr       */
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
	std::string	effects;
	ASpell( void );
	ASpell( ASpell const& other );
	ASpell&	operator=( ASpell const& other );
public:
	ASpell( std::string name, std::string effects );
	virtual ~ASpell();

	std::string const&	getName( void ) const;
	std::string const&	getEffects( void ) const;
	void				launch( ATarget const& target );

	virtual ASpell*		clone( void ) const = 0;
};

#endif