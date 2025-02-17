/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 03:44:43 by gitkim            #+#    #+#             */
/*   Updated: 2025/02/17 22:28:19 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class WrongAnimal
{
protected:
	std::string	type;
public:
	WrongAnimal( void );
	WrongAnimal( const WrongAnimal& other );
	virtual ~WrongAnimal();

	WrongAnimal&	operator=( const WrongAnimal& other );

	void		makeSound( void ) const;
	std::string	getType( void ) const;
};
std::ostream&	operator<<( std::ostream& out, const WrongAnimal& WrongAnimal );

#endif