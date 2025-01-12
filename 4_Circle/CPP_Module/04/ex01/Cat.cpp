/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 03:27:15 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/12 18:29:45 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Cat.hpp"

Cat::Cat( void ) : Animal(), catsBrain(new Brain())
{
	type = "Cat";
	std::cout << "Cat Default constructor called" << std::endl;
}

Cat::Cat( const Cat& other ) : Animal(other), catsBrain(new Brain(*other.catsBrain))
{
	std::cout << "Cat Copy constructor called" << std::endl;
}

Cat::~Cat()
{
	delete (catsBrain);
	std::cout << "Cat Destructor called" << std::endl;
}

Cat&	Cat::operator=( const Cat& other )
{
	if (this != &other)
	{
		if (catsBrain)
			delete (catsBrain);
		Animal::operator=(other);
		*catsBrain = *other.catsBrain;
	}
	return (*this);
}

std::ostream&	operator<<( std::ostream& out, const Cat& Cat )
{
	out	<< Cat.type << std::endl;
	return (out);
}

void	Cat::makeSound( void ) const
{
	std::cout << "meowwww.." << std::endl;
}
