/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 02:53:33 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/12 18:17:27 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat( void );
	Cat( const Cat& other );
	virtual ~Cat();

	Cat&					operator=( const Cat& other );
	friend std::ostream&	operator<<( std::ostream& out, const Cat& Cat );

	void	makeSound( void ) const;
};

#endif