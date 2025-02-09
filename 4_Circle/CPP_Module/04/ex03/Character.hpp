/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:57:35 by gitkim            #+#    #+#             */
/*   Updated: 2025/02/09 21:16:43 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <string>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	std::string	name;
	AMateria*	inventory[4];
public:
	Character( void );
	Character( const std::string& name );
	Character( const Character &other );
	virtual ~Character();

	Character&	operator=( const Character &other );
	
	virtual std::string const&	getName( void ) const;
	virtual void				equip( AMateria* m );
	virtual void				unequip( int idx );
	virtual void				use( int idx, ICharacter& target );
};

#endif