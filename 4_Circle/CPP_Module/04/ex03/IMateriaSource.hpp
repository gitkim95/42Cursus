/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 20:37:36 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/13 20:55:15 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include <string>
# include "AMateria.hpp"

class IMateriaSource
{
private:
	/* data */
public:
	IMateriaSource( void );
	IMateriaSource( const IMateriaSource& other );
	virtual ~IMateriaSource();

	IMateriaSource&	operator=( const IMateriaSource& other );
	
	virtual void		learnMateria(AMateria*) = 0;
	virtual AMateria*	createMateria(std::string const & type) = 0;
};

#endif