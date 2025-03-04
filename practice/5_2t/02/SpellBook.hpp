/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:39:39 by gitkim            #+#    #+#             */
/*   Updated: 2025/03/04 17:58:44 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

# include <map>
# include <string>

class ASpell;

class SpellBook
{
private:
	std::map<std::string, ASpell*>	spells;
	SpellBook( SpellBook const& other );
	SpellBook&	operator=( SpellBook const& other );
public:
	SpellBook( void );
	~SpellBook();

	void	learnSpell( ASpell* spell );
	void	forgetSpell( std::string const& spellName );
	ASpell*	createSpell( std::string const& spellName );
	std::map<std::string, ASpell*>&	getSpells( void );
};

#endif