/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 03:45:46 by gitkim            #+#    #+#             */
/*   Updated: 2025/02/08 14:51:34 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	WRONGCAT_HPP
# define WRONGCAT_HPP

# include <string>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat( void );
	WrongCat( const WrongCat& other );
	virtual ~WrongCat();

	WrongCat&	operator=( const WrongCat& other );

	void	makeSound( void ) const;
};
std::ostream&	operator<<( std::ostream& out, const WrongCat& WrongCat );

#endif