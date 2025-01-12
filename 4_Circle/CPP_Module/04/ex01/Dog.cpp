/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 03:28:32 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/12 18:30:34 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Dog.hpp"

Dog::Dog( void ) : Animal(), dogsBrain(new Brain())
{
	type = "Dog";
	std::cout << "Dog Default constructor called" << std::endl;
}

Dog::Dog( const Dog& other ) : Animal(other), dogsBrain(new Brain(*other.dogsBrain))
{
	std::cout << "Dog Copy constructor called" << std::endl;
}

Dog::~Dog()
{
	delete (dogsBrain);
	std::cout << "Dog Destructor called" << std::endl;
}

Dog&	Dog::operator=( const Dog& other )
{
	if (this != &other)
	{
		if (dogsBrain)
			delete (dogsBrain);
		Animal::operator=(other);
		*dogsBrain = *other.dogsBrain;
	}
	return (*this);
}

std::ostream&	operator<<( std::ostream& out, const Dog& Dog )
{
	out	<< Dog.type << std::endl;
	return (out);
}

void	Dog::makeSound( void ) const
{
	std::cout << "grrrrrr.." << std::endl;
}
