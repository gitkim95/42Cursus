/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 03:58:06 by gitkim            #+#    #+#             */
/*   Updated: 2025/03/04 04:47:53 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

# include <string>
# include <map>
class ASpell;

class SpellBook
{
private:
	std::map<std::string, ASpell*>	skills;
	SpellBook( const SpellBook& other );
	SpellBook& operator=( const SpellBook& other );
public:
	SpellBook( void );
	~SpellBook( void );

	void	learnSpell( ASpell* spell );
	void	forgetSpell( std::string& spellName );
	ASpell*	createSpell( std::string& spellName );
	std::map<std::string, ASpell*>&	getSkills( void );
};

#endif