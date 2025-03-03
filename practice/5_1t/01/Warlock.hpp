/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 21:09:14 by gitkim            #+#    #+#             */
/*   Updated: 2025/03/04 03:15:09 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <string>
# include <map>

class ASpell;
class ATarget;

class Warlock
{
private:
	std::string	name;
	std::string title;
	std::map<std::string, ASpell*>	skill;
	
	Warlock( void );
	Warlock( const Warlock& other );
	Warlock& operator=( const Warlock& other );
public:
	Warlock( std::string name, std::string title );
	~Warlock();

	std::string const&	getName( void ) const;
	std::string const&	getTitle( void ) const;
	void				setTitle( std::string const& newTitle );

	void				introduce() const;
	void				learnSpell( ASpell* spell );
	void				forgetSpell( std::string spellName );
	void				launchSpell( std::string spellName, ATarget& target );
};

#endif