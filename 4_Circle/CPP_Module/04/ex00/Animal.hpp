/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 02:53:33 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/08 18:47:27 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal
{
protected:
	std::string	type;
public:
	Animal( void );
	Animal( std::string type );
	Animal( const Animal& other );
	virtual ~Animal();

	Animal&					operator=( const Animal& other );
	friend std::ostream&	operator<<( std::ostream& out, const Animal& Animal );

	virtual void	makeSound( void ) const;
	std::string		getType( void ) const;
	
};

#endif