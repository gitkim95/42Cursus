/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:09:24 by gitkim            #+#    #+#             */
/*   Updated: 2025/02/11 12:14:15 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria*	source[4];
public:
	MateriaSource( void );
	MateriaSource( const MateriaSource& other );
	virtual ~MateriaSource( void );

	MateriaSource&	operator=( const MateriaSource& other );

	virtual void		learnMateria( AMateria* source );
	virtual AMateria*	createMateria( std::string const& type );
};

#endif