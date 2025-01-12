/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 23:57:44 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/13 01:19:40 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>

class AMateria
{
protected:
	std::string	type;
public:
	AMateria( void );
	AMateria( std::string const &type );
	AMateria( const AMateria& other );
	virtual ~AMateria();

	AMateria&	operator=( const AMateria& other );

	std::string const &getType( void ) const; //Returns the materia type
	virtual AMateria* clone( void ) const = 0;
	virtual void use( ICharacter& target );
};

#endif