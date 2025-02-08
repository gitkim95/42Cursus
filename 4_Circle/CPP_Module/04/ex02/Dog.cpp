/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 03:28:32 by gitkim            #+#    #+#             */
/*   Updated: 2025/02/08 14:50:53 by gitkim           ###   ########.fr       */
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
	std::cout << "Dog Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		if (dogsBrain)
			delete (dogsBrain);
		Animal::operator=(other);
		dogsBrain = new Brain(*other.dogsBrain);
	}
	return (*this);
}

std::ostream&	operator<<( std::ostream& out, const Dog& Dog )
{
	out	<< Dog.getType() << std::endl;
	return (out);
}

void	Dog::makeSound( void ) const
{
	std::cout << "grrrrrr.." << std::endl;
}
