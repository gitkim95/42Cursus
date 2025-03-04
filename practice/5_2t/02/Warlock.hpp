/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:06:59 by gitkim            #+#    #+#             */
/*   Updated: 2025/03/04 17:56:23 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <string>
# include <map>
# include "SpellBook.hpp"
class ASpell;
class ATarget;

class Warlock
{
private:
	std::string	name;
	std::string	title;
	SpellBook	spells;
	Warlock( void );
	Warlock( Warlock const& other );
	Warlock&	operator=( Warlock const& other );
public:
	Warlock( std::string name, std::string title );
	~Warlock();

	std::string const&	getName( void ) const;
	std::string const&	getTitle( void ) const;
	void				setTitle( std::string const& newTitle );

	void				introduce( void ) const;
	void				learnSpell( ASpell* spell );
	void				forgetSpell( std::string const& spellName );
	void				launchSpell( std::string const& spellName, ATarget& target );
};

#endif