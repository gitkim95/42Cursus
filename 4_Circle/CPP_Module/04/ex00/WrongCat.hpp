/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 03:45:46 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/12 16:37:12 by gitkim           ###   ########.fr       */
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
	WrongCat( std::string type );
	WrongCat( const WrongCat& other );
	virtual ~WrongCat();

	WrongCat&				operator=( const WrongCat& other );
	friend std::ostream&	operator<<( std::ostream& out, const WrongCat& WrongCat );

	void	makeSound( void ) const;
};

#endif