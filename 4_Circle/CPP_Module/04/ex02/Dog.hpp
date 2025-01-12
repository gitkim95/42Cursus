/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 02:53:33 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/12 18:18:42 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain*	dogsBrain;
public:
	Dog( void );
	Dog( const Dog& other );
	virtual ~Dog();

	Dog&					operator=( const Dog& other );
	friend std::ostream&	operator<<( std::ostream& out, const Dog& Dog );

	void	makeSound( void ) const;
};

#endif