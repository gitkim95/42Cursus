/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 03:28:32 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/12 22:59:56 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Dog.hpp"

Dog::Dog( void ) : Animal()
{
	type = "Dog";
	std::cout << "Dog Default constructor called" << std::endl;
}

Dog::Dog( const Dog& other ) : Animal(other)
{
	std::cout << "Dog Copy constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
}

Dog&	Dog::operator=( const Dog& other )
{
	std::cout << "Dog Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		type = other.type;
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
